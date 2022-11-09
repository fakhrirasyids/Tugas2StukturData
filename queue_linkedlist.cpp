#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode{
    int nilaiX;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    return tail == NULL;
}

void inqueue(int databaru1)
{
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru1;
    baru->next = NULL;

    if(isEmpty()) {
        head=tail=baru;
    } else {
        tail->next = baru;
        tail=baru;
    }
    cout<<"Data masuk\n";
}

void dequeue()
{
    TNode *hapus;
    int d, e;
    string targetTemp;

    if (!isEmpty()) {
        if(head!=tail) {
            hapus=head;
            d=hapus->nilaiX;
            head=head->next;
            delete hapus;
        }else{
            d=tail->nilaiX;
            head=tail=NULL;
        }

        cout<< d << " terhapus";
    } else cout<<"Masih kosong\n";
}

void tampil(){
    TNode *bantu;
    bantu=head;

    if(!isEmpty()) {
        int idx = 1;
        while(bantu!=NULL) {
            cout << idx << ". " << bantu->nilaiX << " " << endl;
            bantu=bantu->next;
            idx++;
        }
    } else {
        cout <<"Masih kosong\n";
    }
}

int main()
{
    int pil, databaru1;
    string dataTarget;

    do
    {
        cout<<endl;
        cout<<" ============================"<<endl;
        cout<<" =       PROGRAM STACK      ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. INQUEUE               ="<<endl;
        cout<<" = 2. DEQUEUE               ="<<endl;
        cout<<" = 3. Tampil Data           ="<<endl;
        cout<<" = 4. Exit                  ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: system("CLS");{
                cout<<"Masukan Data 1 = ";cin>>databaru1;
                inqueue(databaru1);
                break;
            }
            case 2: system("CLS");{
                dequeue();
                break;
            }
            case 3: system("CLS");{
                tampil();
                break;
            }
            default : system("CLS");
            {
                cout<<"\n Terimakasih telah menggunakan aplikasi ini!";
            }
        }
    }
    while (pil!=4);
}