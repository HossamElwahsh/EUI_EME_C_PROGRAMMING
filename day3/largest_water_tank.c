#include "largest_water_tank.h"

static int calc_area(int start_index,int end_index, int * arr)
{
    int width, height, area;

    /* Calculate width */
    width = end_index - start_index;

    /* Calculate Minimum Height */
    height = MIN(arr[start_index], arr[end_index]);

    /* Calculate and return area (w * h) */
    area = width * height;

    return area;
}

int find_largest_area(int * arr, int n)
{
   int int_retval_largest_area = 0;

   if((NULL_PTR != arr) && (n > MIN_ARRAY_SIZE))
   {
       int area, right;

       right = n - 1;

       for (int left = 0; left < n; left++)
       {

           /* calculate area */

           if(arr[right] > arr[left])
           {
                left--;
           }
           else if(arr[left] > arr[right])
           {
               right--;
           }

           area = calc_area(left, right, arr);

           if(int_retval_largest_area < area)
           {
               int_retval_largest_area = area;
           }

           //if(left == right) break;
       }
   }
   else
   {
       printf("Invalid input\n");
   }

    return int_retval_largest_area;
}