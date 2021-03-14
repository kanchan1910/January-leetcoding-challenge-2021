//jan 1 2021

// Write a function that checks whether any permutation of a string is a palindrome.

bool fun(string str){

    int e=0,o=0;
    unordered_map<char,int>m;
    for(int i=0;i<str.length();i++){
        m[str[i]]++;
    }
    for(auto x:m){
        if(x.second%2==0){
            e++;
        }
        else{
            o++;
        }
    }
    return o<=1;
}
// tc o(n)
//sc o(n)

/*
Brute force :
generate all permutations of a given input string and then check each permutaion whether it is a palidrome by checking string==reverse(string)
tc o(n^3)
sc o(1)
*/
/*efficient solution
ab jo b input string h usme jo hr element ki frequency hogi vhi uske sbhi permutaions m b hogi 
or agar uske elements ki frequencies palindomic ki quality ko staisfy kr ri ho or bhale abhi vo khudh palindrome ni ho pr uski koi na koi permutation jarur hogi
or agar uske elements ki frequnecies hi palindrome ko quality ko satisfy ni kr ri h to uski koi b permutation b ni kregi

tc o(n)
sc o(n)
*/
