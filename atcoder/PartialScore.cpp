#include <bits/stdc++.h>
using namespace std;
char ans;
void merge(string &s, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<char> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = s[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = s[mid + i + 1];
    int i = 0, j = 0;
    int k = left;

    while(i < n1 && j < n2){
        cout << "? " << L[i] << " " << R[j] << endl;
        fflush(stdout);
        cin >> ans;
        if(ans == '<'){
            s[k] = L[i];
            i++;
        }
        else{
            s[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        s[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        s[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(string &s, int left, int right){
   if(left >= right) return;

   int mid = left + (right - left)/2;
   mergeSort(s, left, mid);
   mergeSort(s, mid+1, right);
   merge(s, left, mid, right);
}

bool isBigger(char c1, char c2){
    cout << "? " << c1 << " " << c2 << endl;
    fflush(stdout);
    cin >> ans;
    if(ans == '>') return true;

    return false;
}

void sort7comparision(string &s){
    if(isBigger(s[0], s[1])) swap(s[0], s[1]);
    if(isBigger(s[2], s[3])) swap(s[2], s[3]);

    if(isBigger(s[0], s[2])){
        swap(s[0], s[2]);
        swap(s[1], s[3]);
    }

    if(isBigger(s[4], s[2])){
        if(isBigger(s[3], s[4])){
            swap(s[3], s[4]);
        }
    }
    else {
        if(isBigger(s[4], s[0])){
            swap(s[2], s[4]);
            swap(s[4], s[3]);
        }
        else{
            swap(s[0], s[2]);
            swap(s[4], s[3]);
            swap(s[3], s[0]);
        }
    }

    if(isBigger(s[1], s[3])){
        if(isBigger(s[1], s[4])){
            swap(s[1], s[2]);
            swap(s[4], s[3]);
            swap(s[2], s[4]);
        }
        else{
            swap(s[1], s[2]);
            swap(s[2], s[3]);
        }
    }
    else{
        if(isBigger(s[1], s[2])){
            swap(s[1], s[2]);
        }
    }
}


int main(){
    int N,Q;
    cin >> N >> Q;
    string s;
    for (int i=0; i < N; i++) {
        s += (char) ('A' + i);
    }

    //merge insertion
    if(N == 5)
        sort7comparision(s);
    else
        mergeSort(s, 0, N-1);


    cout << "! " << s << endl;

    return 0;
}
