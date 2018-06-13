/* insertion sort */
insertion_sort(item s[], int n){
    int i,j; 
    for(i=0;i<n;i++){
        j = i;
        while( (j>0) && (s[j] < s[j-1]) ){
            swap(&s[j],&s[j-1]);
            j -= 1;
        }
    }