

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int sum;
  for (int i=0;i<number_of_students;i++){
    
        if (gender=='b'){
            if (i%2==0){
                sum+=marks[i];
            }
        }else if (gender=='g'){
            if (i%2!=0){
                sum+=marks[i];
            }
        }
  
    }
    
    return sum;
}

