#include "black_box"

void crash(int *i){
	*i = 1;
}
void f(int *i){
	int *j = i;
	j = sophisticated();
	j = complicated(j);
	crash(j);
}
int main(){
	int i
	f(&1);
}

