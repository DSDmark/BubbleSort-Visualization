<div align="center">

##  How this Application works 

</div>
  
#### About the Algorithms

> Sorting can be referred to as arranging files in some particular order. The arrangement performed can be based on the value of each file present. That particular order can be in either an ascending or descending fashion. Sorting algorithms are instructions given to a computer to arrange elements in a particular order.

- Bubble sort follows the recursion technique.

#### Step-by-step guide:

-   Start by comparing the first two elements in an array.
    
-   Swap them if required.
    
-   Continue till the end of the array. At this point, you have made a series of inner passes and completed an outer pass.
    
-   Repeat the process until the entire array is sorted.

<div align="center">

![**Bubble Sort**](https://miro.medium.com/max/259/1*7QsZkfrRGhAu5yxxeDdzsA.png)
</div>

```js
function bubbleSort(arr){

    //Outer pass
    for(let i = 0; i < arr.length; i++){

        //Inner pass
        for(let j = 0; j < arr.length - i - 1; j++){

            //Value comparison using ascending order

            if(arr[j + 1] < arr[j]){

                //Swapping
                [arr[j + 1],arr[j]] = [arr[j],arr[j + 1]]
            }
        }
    };
    return arr;
};

console.log(bubbleSort([5,3,8,4,6]));
```

### Output:-

> `[ 3, 4, 5, 6, 8 ]`

Here is detailed artical about that:- [**Sorting**](https://www.section.io/engineering-education/sorting-algorithms-in-js/#bubble-sort)


