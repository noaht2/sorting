#include <stdlib.h>
#include <stdio.h>

typedef char t;

void swap(t *a, t *b)
{
     t temp = *a;
     *a = *b;
     *b = temp;
}

void bubble_sort(t list[], int length)
{
     if (length == 0) {
	  return;
     } else {
	  for (int i = 0; i < length-1; i++) {
	       if (list[i] > list[i+1]) {
		    swap(list+i, list+i+1);
	       }
	  }
	  bubble_sort(list, length-1);
     }
}

void shuttle(t list[], int pos)
{
     if (pos != 0) {
	  if (list[pos-1] > list[pos]) {
	       swap(list+pos-1, list+pos);
	       shuttle(list, pos-1);
	  }
     }
}

void shuttle_sort(t list[], int length)
{
     for (int i = 1; i < length; i++) {
	  shuttle(list, i);
     }
}

void quick_sort(t list[], int length)
{
     if (length < 2) {
	  return;
     }
     
     t *pivoted;
     pivoted = malloc(length);

     int i = 0;
     int j;
     for (j = 1; j < length; j++) {
	  if (list[j] < list[0]) {
	       pivoted[i] = list[j];
	       i++;
	  }
     }
     quick_sort(pivoted, i);
     pivoted[i] = list[0];
     int second_sublist_start = i+1;
     i++;
     for (j = 1; j < length; j++) {
	  if (list[j] > list[0]) {
	       pivoted[i] = list[j];
	       i++;
	  }
     }

     quick_sort(pivoted+second_sublist_start, length-second_sublist_start);

     for (i = 0; i < length; i++) {
	  list[i] = pivoted[i];
     }

     free(pivoted);
}

int main()
{
     t l[] = "qwertyuiopasdfghjklzxcvbnm";
     quick_sort(l, 26);
     puts(l);
     return 0;
}
