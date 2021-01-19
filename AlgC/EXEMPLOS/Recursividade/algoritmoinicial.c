
double p1(double x, unsigned int n){
    if(n>0) return x*p(x,n-1);
    return 1;
}
