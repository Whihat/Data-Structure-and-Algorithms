/* * * * * * *
 * Module for functions that solve the coding tasks from assignment 1
 *
 * created for COMP20007 Design of Algorithms - Assignment 1, 2018
 * by Matt Farrugia <matt.farrugia@unimelb.edu.au>
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "query.h"
#include "heap.h"

void update_topk(Heap *topk, float score, int docid);
void print_results(Heap *topk);

void print_array_results(Index *index, int n_results, int n_documents) {

	// first we need to accumulate document scores into an array

	// set up a blank array to store the score for each document
	// a document with id x has its score stored at docscores[x]
	float *docscores = malloc(n_documents * sizeof *docscores);
	assert(docscores);
	for (int id = 0; id < n_documents; id++) {
		docscores[id] = 0;
	}

	// go through the index's document lists, accumulating the
	// scores from each document list into this array
	for (int i = 0; i < index->num_terms; i++) {
		Node *node = index->doclists[i]->head;
		while (node) {
			Document *document = node->data;
			docscores[document->id] += document->score;

			node = node->next;
		}
	}


	// now we have the completed score array, run the top-k algorithm
	// to find the top n_results non-zero scores and ids in the array

	// a min-heap with scores as keys and document ids as data
	Heap *topk = new_heap(n_results);
	for (int id = 0; id < n_documents; id++) {
		if (docscores[id] > 0) {
			update_topk(topk, docscores[id], id);
		}
	}

	// extract and output results in decreasing order, as required
	print_results(topk);


	// all done!
	free(docscores);
	free_heap(topk);
}

void print_merge_results(Index *index, int n_results) {

	// iterate through the scores in all the doclists concurrently,
	// in order of increasing document id.

	// we'll need a heap to run the top-k algorithm while we iterate
	Heap *topk = new_heap(n_results);

	// and we'll need a priority queue for that: a min-heap with
	// document ids as keys and document list nodes as data
	Heap *nodes = new_heap(index->num_terms);
	for (int i = 0; i < index->num_terms; i++) {
		Node *node = index->doclists[i]->head;
		if (node) {
			Document *document = node->data;
			heap_insert(nodes, document->id, node);
		}
	}

	// with those set up, let's iterate until we exhaust all the lists!
	while (heap_size(nodes)) {

		// which document id is next? let's start counting up it's score
		int current_docid = heap_peek_key(nodes);
		float current_score = 0;

		// now, find and sum all of the scores for this document id
		// (take from the priority queue until there's a different document
		// id at the front)
		while (heap_size(nodes) && heap_peek_key(nodes) == current_docid) {

			// add the score from the next document list entry to the
			// total score for this document id
			Node *node = heap_peek_min(nodes);
			Document *doc = node->data;
			current_score += doc->score;

			// then, advance our progress through this list in the
			// multi-way merge:

			// remove this node from the priority queue
			heap_remove_min(nodes);

			// if this was not the last node, insert the next node, with its
			// document's id as the key
			if (node->next) {
				Document *next_doc = node->next->data;
				heap_insert(nodes, next_doc->id, node->next);
			}
		}

		// okay, we have generated a new score. take the next step in
		// the top-k algorithm!
		update_topk(topk, current_score, current_docid);
	}


	// extract and output results in decreasing order, as required
	print_results(topk);

	// all done!
	free_heap(nodes);
	free_heap(topk);
}

void update_topk(Heap *topk, float score, int docid) {
	// tricky: store the integer docid in the heap data directly by
	// prtending it's a void pointer (later we will need to cast it
	// back to an integer instead of dereferencing it)
	void *docid_as_ptr = (void *)(intptr_t)docid;

	// if there's still space in the heap, we can just add the new score
	int k = heap_max_size(topk);
	if (heap_size(topk) < k) {
		heap_insert(topk, score, docid_as_ptr);

	// otherwise we'll only add it if it's large enough, in which case
	// we'll kick out the smallest existing score to make space
	} else if (heap_peek_key(topk) < score) {
		heap_remove_min(topk);
		heap_insert(topk, score, docid_as_ptr);
		// note: could improve efficiency by combining into a new
		// 'heap_replace_min' function which does both at once
	}
}

void print_results(Heap *topk) {
	// pull the scores out of the heap in smallest-to-largest order,
	// placing them backwards into two arrays (one for scores and one
	// for document ids)
	int k = heap_size(topk);
	float *scores = malloc(k * sizeof *scores);
	assert(scores);
	int *docids = malloc(k * sizeof *docids);
	assert(docids);

	for (int i = k-1; i >= 0; i--) {
		scores[i] = heap_peek_key(topk);
		docids[i] = (int)(intptr_t)heap_peek_min(topk); // see update_topk()
		heap_remove_min(topk);
	}

	// now loop through these arrays and print out the scores in the
	// required format
	for (int i = 0; i < k; i++) {
		printf("%6d %.6f\n", docids[i], scores[i]);
	}

	// all done!
	free(scores);
	free(docids);
}
