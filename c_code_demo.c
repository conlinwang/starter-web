//C hello world example
#include <stdio.h>
#include <time.h>
// #include <conio.h>

void my_function();
int max(int, int);

int solution(int A[], int );
int solution_2(int N) ;
int solution_3(int A[], int N); 
int solution_4(int A[], int N, int X, int D);

int solution_5(char *E, char *L);

void getSeconds(unsigned long *par);

void showbits(unsigned int x){
  int i; 
  for(i=(sizeof(int)*8)-1; i>=0; i--){
    (x&(1<<i))?putchar('1'):putchar('0');
  }
    
  printf("\n");
}

int main()
{

  printf("Hello world\n");
  int c =0;

  // int array[8] = {-3, 3, -4, 5, 1, -6, 2, 1};
  int array[3] = {1, 0, 0};
  double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};

  my_function();
  printf("Back in function main.\n");

  c = solution(array, 3);

  printf("value of c : %d \n", c);

  // int j = 9736, m, n;
  // printf("The decimal %d is equal to binary - \n", j);
  // showbits(j);
  // /* the loop for right shift operation */
  // for ( m = 0; m <= 30; m++ ) {
  //   n = j >> m;
  //   printf("%d right shift %d gives ", j, m);
  //   // showbits(n);
  //   printf("The decimal %d is equal to binary - \n", n);
  // }
  // showbits(9736);

  // c = solution_2(809500676);
  // printf("value of c : %d \n", c);
  // int array_3 [8] = {0, 3, 3, 7, 5, 3, 11, 1};
  // int array_4 [6] = {1, 4, 7, 3, 3, 5};
  // c = solution_3(array_3, 8);
  // printf("value of c : %d \n", c);

  // c = solution_3(array_4, 6);
  // printf("value of c : %d \n", c);

  int array_5 [6] = {1, 3, 1, 4, 2, 5};
  c = solution_4(array_5, 6, 7, 3);
  printf("value of c : %d \n", c);

  char Enter[5] = "10:00";
  char Leaf[5] = "13:21";
  // char *E = &Enter;
  // char *L = &Leaf;

  c = solution_5(Enter, Leaf);
  printf("value of c : %d \n", c);
 

  // unsigned long sec;
  // getSeconds( &sec );

  //   print the actual value 
  //  printf("Number of seconds: %ld\n", sec );


  return 0;
}

int solution_5(char *E, char *L) {
    printf("%s\n",E);
    printf("seperate\n");
    printf("%s\n",E);

    printf("%s\n",L);
    for (int i = 0; i < 2; ++i)
    {
      printf("%s\n", E[i]);
    }



    return 10;
}

void getSeconds(unsigned long *par) {
   /* get the current number of seconds */
   *par = time( NULL );
   return;
}

int solution_4(int A[], int N, int X, int D) {
  int current_position = 0;
  int current_time = 0;
  int destination = X;
  int i=0;
  if(X <= D){
    return 0;
  }

  for (i = 0; i < N; i++) {
    // printf("i = %d, A[i] = %d\n", i, A[i] );
    if( (A[i] - current_position < 4) && (A[i] - current_position > 0) && (A[i] <= X) ){
      current_position = A[i];
      current_time = i;
      if(X - current_position <= D){
        return current_time;
      }

    }
    if(i == N-1 && current_position < X){
      return -1;
    }

  }
  return -2;
}

int solution_2(int N) {
    int largest = N;
    int shift = 0;
    int temp = N;
    int i;
    for (i = 1; i < 30; ++i) {
        int index = (temp & 1); // the right most bit
        printf("index = %d , i = %d ", index, i);
        temp = ((temp >> 1) | (index << 29)); // shift right one bit and add the index onto the left most
        printf("temp= %d ", temp);
        printf(" largest = %d, shift = %d \n", largest, i);
        if (temp > largest) {
            largest = temp;
            shift = i;
        }
    }
    return shift;
}

int solution_3(int A[], int N){
  int i;
  int j;
  int k;
  int have_adjacent_value = 0;
  int distance = 0;
  int smallest_distance = 4000000;
  for( i = 0; i < N-1; i++){
    for( j = i + 1; j < N; j++){
      printf("(i,j) = (%d, %d) = A[%d]=%d, A[%d]=%d ", i, j, i, A[i] ,j,  A[j]);
  
      if( (A[j] - A[i]) != 0){
        have_adjacent_value = 1;
        for( k = 0; k < N ; k++){
        if(     ( A[i] < A[k]) &&  ( A[k] < A[j] ) ) {
          have_adjacent_value = 0;
        }
        if(  ( A[k] > A[j] ) &&  ( A[k] < A[i] )   ) {
         have_adjacent_value = 0; 
        }
        // else{
        //  have_adjacent_value = 1; 
        // }
      }// end of for loop

      }
      else{
        have_adjacent_value = 0; 
      }
      
      printf("have_adjacent_value= %d ", have_adjacent_value);
      if(have_adjacent_value == 1){
        distance = j-i;
        if(distance < smallest_distance){
          smallest_distance = distance;
        }

      }
      printf("distance= %d \n", distance);
    }
    distance = 0;
    have_adjacent_value = 0;
  }

  if(smallest_distance == 4000000){
    return -1; 
  }
  else{
    return smallest_distance; 
  }

  return -2; 
}

void my_function(){
   printf("Welcome to my function. Feel at home.\n");
}

int solution(int A[], int N) {
  if (N==0) return -1; 
  long long sum = 0;
  int i; 
  for(i=0; i< N; i++) sum+=(long long) A[i]; 
  long long sum_left = 0;    
  for(i=0; i<N ; i++) {
        long long sum_right = sum - sum_left - (long long) A[i];
        if (sum_left == sum_right) return i;
        sum_left += (long long) A[i];
    } 
    return -1; 
}



int max(int num1, int num2) {

   /* local variable declaration */
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}