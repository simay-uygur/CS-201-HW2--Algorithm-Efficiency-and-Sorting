#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

static int totalcompare=0;
static int totalSwaps =0 ;
static int totalDurationOperations = 0; 

const static int size1 = 8, size2 = 16, size3 = 32, size4 = 64, size5 = 128 , size6 = 256,
        size7 = 512, size8 = 1024, size9 = 2048 , size10= 4096;

int intArr[10] = {size1, size2, size3, size4, size5 , size6 ,size7, size8 , size9 , size10};

int *generate_random_array(int size) {
    int* newArr = new int[size];

    for(int a=0; a< size; ++a )
        newArr[a] = rand();

    return newArr;
}

//my checking method
bool isSorted(const int* checkArr, int size)
{
    if(size <=1)
        return true;
    int prev = checkArr[0];

    for(int g=1; g<size; ++g){
        if(checkArr[g] < prev)
            return false;
        prev = checkArr[g];
    }
    return true;
}

//for generated almost sorted array
void trySort(int theArray[], int n) {  // same as insertion sort but without count
    for (int unsorted = 1; unsorted < n; ++unsorted) {

        int nextItem = theArray[unsorted];

        int loc = unsorted;
        for ( ;(loc > 0) && (theArray[loc-1] > nextItem); --loc)
        {
            theArray[loc] = theArray[loc-1];

        }
        theArray[loc] = nextItem;

    }
}
bool isAlmostSorted(const int arr[], int size){

    int incorrectpos =0;
    int* tempCompare = new int[size];

    for (int n = 0; n< size; ++n) {
        tempCompare[n] = arr[n];
    }

    trySort(tempCompare,size);

    for (int i = 0; i < size; ++i) {
       if(arr[i] != tempCompare[i])
           incorrectpos++;
    }
    delete[] tempCompare;

    return ( incorrectpos >= (size * 0.06));
}

int *generate_almost_sorted_array(int size) {

    int *random_array = generate_random_array(size);

    trySort(random_array,size);
    int swap_count = size * 0.03;

    if(swap_count < 1) // this is for small arrays not to become fully sorted have at least one element in the other posiiton
    {
        swap_count = 1;  //make sure at least one
    }

    for (int i = 0; i < swap_count; i++) {
        int first_index = std::rand() % size;
        int second_index = size - first_index;
        int temp = random_array[first_index];
        random_array[first_index] = random_array[second_index];
        random_array[second_index] = temp;
    }
    return random_array;
}

void insertionSort(int theArray[], int n) {
    for (int unsorted = 1; unsorted < n; ++unsorted) {

        int nextItem = theArray[unsorted];
        totalSwaps+=5;
        totalDurationOperations+=5;
        int loc = unsorted;
        for ( ;(loc > 0) && (theArray[loc-1] > nextItem); --loc)
        {
            theArray[loc] = theArray[loc-1];
            totalcompare++; // total num of compares
            totalSwaps+=5;
            totalDurationOperations+=6;
        }
        theArray[loc] = nextItem;
        totalSwaps+=5;
        totalDurationOperations+=5;
        if(loc >0)
        {
            totalcompare++; // the last comparison to exit for loop if the loc is positive
            totalDurationOperations++;
        }

    }
}

//for selection sort
int indexOfLargest(const int theArray[], int size) {
    int indexSoFar = 0;
    for (int currentIndex=1; currentIndex<size; ++currentIndex){
        if (theArray[currentIndex] > theArray[indexSoFar])
            indexSoFar = currentIndex;
        totalcompare++;
        totalDurationOperations++;

    }
    return indexSoFar;
}
//for selection sort and quicksort
void swap(int &x, int &y) {
    //cout << "Swapping elements in method " << x << " and " << y << std::endl;
    int temp = x;
    x = y;
    y = temp;
    totalSwaps +=15;
    totalDurationOperations+=15;
}

void selectionSort(int theArray[], int n) {
    for (int last = n-1; last >= 1; --last) {
        int largest = indexOfLargest(theArray, last+1);
        swap(theArray[largest], theArray[last]);
    }
}

void bubbleSort(int theArray[], int n) {
    bool sorted = false;
    for (int pass = 1; (pass < n) && !sorted; ++pass) {
        sorted = true;
        for (int index = 0; index < n - pass; ++index) {
            int nextIndex = index + 1;

            if (theArray[index] > theArray[nextIndex]) {
                swap(theArray[index], theArray[nextIndex]);
                sorted = false;
            }
            totalcompare++;
            totalDurationOperations++;
        }
    }
}

//quick sortta kullanılıyor  belki bir tane daha eklerim
void choosePivot(int theArray[], int first, int last)  //random alsın
{
    /* // i have chosen randomness for the task3
    int indexPivot = first + rand() % (last - first + 1);

    //int indexPivot = rand() % (last- first+1 );
    int temp = theArray[indexPivot];
    theArray[indexPivot] = theArray[first];
    theArray[first] = temp;

    totalSwaps+=15;

    totalDurationOperations+=15;*/

}

void partition(int theArray[], int first, int last, int &pivotIndex) {

    choosePivot(theArray, first, last);
    int pivot = theArray[first]; // copy pivot

    int lastS1 = first;
    int firstUnknown = first + 1;

    for ( ; firstUnknown <= last; ++firstUnknown) {
        if (theArray[firstUnknown] < pivot) {
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1]); //kendi içinde artırıyor totalswapi
        }
        totalcompare++;
        totalDurationOperations++;
    }
    swap(theArray[first], theArray[lastS1]);
    pivotIndex = lastS1;
}

void quicksort(int theArray[], int first, int last) {

    int pivotIndex;
    if (first < last) {
        // create the partition: S1, pivot, S2

        partition(theArray, first, last, pivotIndex);
        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex-1);
        quicksort(theArray, pivotIndex+1, last);

    }
}


#include <iostream>
#include <thread>


/*
int partition3(int arr[], int low, int high, CountInfo& count) {
    int index = low + rand() % (high - low + 1);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        count.comparisons++;  // Increment comparison count
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            count.swaps++;  // Increment swap count
        }
    }
    std::swap(arr[i + 1], arr[high]);
    count.swaps++;  // Increment swap count
    return i + 1;
}

// Function to perform Quicksort on a subarray
void task3quicksort(int arr[], int low, int high, CountInfo& count) {
    if (low < high) {
        int pi = partition3(arr, low, high, count);
        std::thread left_thread(task3quicksort, arr, low, pi - 1, std::ref(count));
        std::thread right_thread(task3quicksort, arr, pi + 1, high, std::ref(count));
        left_thread.join();
        right_thread.join();
    }
}

// Wrapper function to initiate parallel Quicksort
void parallel_quicksort(int arr[], int size) {
    CountInfo count;
    task3quicksort(arr, 0, size - 1, count);
    std::cout << "Comparisons: " << count.comparisons << ", Swaps: " << count.swaps << std::endl;
}

*/
int main(){
    srand((unsigned int)time(NULL));

    int currentsize; //bunu nasıl yanında yazardım bilemedum
    int * generatedArr = nullptr;


    cout << "Selection Sort " << endl;
    for(int j : intArr){
        totalSwaps = totalcompare= totalDurationOperations= 0; // to restart
        currentsize = j;
        generatedArr = generate_random_array(currentsize);
        selectionSort(generatedArr, currentsize); //burasi ilk insertion kalmış çıldırcam

        cout << "size:  " << currentsize << endl;
        //cout << "total compare  " << totalcompare << endl;
        //cout << "total swaps  " << totalSwaps << endl;
        cout << "total duration " << totalSwaps + totalcompare << endl;
        cout << "is sorted ?  " << isSorted(generatedArr, currentsize) << endl;
        delete[] generatedArr;
    }


     // insertion sort
    cout << "Insertion Sort " << endl;
    for(int j : intArr){
        totalSwaps = totalcompare= totalDurationOperations= 0; // to restart
        currentsize = j;
        generatedArr = generate_random_array(currentsize);
        insertionSort(generatedArr, currentsize);

        cout << "size:  " << currentsize << endl;
        cout << "total compare  " << totalcompare << endl;
        cout << "total swaps  " << totalSwaps << endl;
        cout << "total duration " << totalSwaps + totalcompare << endl;
        cout << "is sorted ?  " << isSorted(generatedArr, currentsize) << endl;
        delete[] generatedArr;
    }


    cout << "Bubble Sort " << endl;
    for(int j : intArr){
        totalSwaps = totalcompare= totalDurationOperations= 0; // to restart
        currentsize = j;
        generatedArr = generate_random_array(currentsize);
        bubbleSort(generatedArr, currentsize);

        cout << "size:  " << currentsize << endl;
        cout << "total compare  " << totalcompare << endl;
        cout << "total swaps  " << totalSwaps << endl;
        cout << "total duration " << totalSwaps + totalcompare << endl;
        cout << "is sorted ?  " << isSorted(generatedArr, currentsize) << endl;
        delete[] generatedArr;
    }
     // three sortings

    cout << "Quick Sort " << endl;
    for(int j : intArr){
        totalSwaps = totalcompare= totalDurationOperations= 0; // to restart
        currentsize = j;
        generatedArr = generate_random_array(currentsize);
        quicksort(generatedArr, 0,currentsize-1 );

        cout << "size:  " << currentsize << endl;
        cout << "total compare  " << totalcompare << endl;
        cout << "total swaps  " << totalSwaps << endl;
        cout << "total duration " << totalSwaps + totalcompare << endl;
        cout << "is " << isSorted(generatedArr,currentsize) << endl;
        delete[] generatedArr;
    }




       cout << "Selection Sort " << endl;
       for(int j : intArr){
            // to restart
           currentsize = j;
           generatedArr = generate_almost_sorted_array(currentsize);
           totalSwaps = totalcompare= totalDurationOperations= 0;
           selectionSort(generatedArr, currentsize); //burasi ilk insertion kalmış çıldırcam

           cout << "size:  " << currentsize << endl;
           cout << "total duration " << totalDurationOperations << endl;
           cout << "is sorted ?  " << isSorted(generatedArr, currentsize) << endl;
           cout << endl;
           delete[] generatedArr;
       }

       cout << "  " << endl;

        // insertion sort
       cout << "Insertion Sort " << endl;
       for(int j : intArr){
           currentsize = j;

           generatedArr = generate_almost_sorted_array(currentsize);  // o kadar saçma hatalar yapmışım ki ağliycam ciddili
           totalSwaps = totalcompare= totalDurationOperations= 0;
           cout << totalDurationOperations;
           insertionSort(generatedArr, currentsize);

           cout << "size:  " << currentsize << endl;

           cout << "total duration " << totalDurationOperations << endl;
           cout << "is sorted ?  " << isSorted(generatedArr, currentsize) << endl;
           cout << endl;
           delete[] generatedArr;
       }

        cout << "  " << endl;
       cout << "Bubble Sort " << endl;
       for(int j : intArr){
           currentsize = j;

           generatedArr = generate_almost_sorted_array(currentsize);
           totalSwaps = totalcompare= totalDurationOperations= 0;
           bubbleSort(generatedArr, currentsize);

           cout << "size:  " << currentsize << endl;

           cout << "total duration " << totalDurationOperations << endl;
           cout << "is sorted ?  " << isSorted(generatedArr, currentsize) << endl;
           cout << endl;
           delete[] generatedArr;
       }
        // three sortings
        cout << "  " << endl;
       cout << "Quick Sort " << endl;
       for(int j : intArr){


           currentsize = j;

           generatedArr = generate_almost_sorted_array(currentsize);
           totalSwaps = totalcompare= totalDurationOperations= 0;
           quicksort(generatedArr, 0,currentsize-1 );

           cout << "size:  " << currentsize << endl;

           cout << "total duration " << totalDurationOperations << endl;
           cout << endl;
           delete[] generatedArr;
       }  //end of task2



}
