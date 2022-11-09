#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int top = 1;
int MAX = 10;

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

int isMax(){
    return top == MAX;
}

void insertBelakang(int databaru1)
{
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru1;
    baru->next = NULL;

    if(isEmpty()) {
        head=tail=baru;
    } else {
        if (isMax()) {
            cout << "Stack penuh!" << endl;
        } else {
            top++;
            tail->next = baru;
            tail=baru;
            cout<<"Data masuk\n";
        }
    }
}

void deleteBelakang() {
    TNode *hapus, *bantu;
    int d, e;
    string targetTemp;

    if (!isEmpty()) {
        if(head!=tail) {
            bantu = head;
            do {
                if (bantu->next->nilaiX == tail->nilaiX) {
                    hapus=tail;
                    d=hapus->nilaiX;
                    tail = bantu;
                    tail->next = NULL;
                    delete hapus;
                    top--;
                    break;
                }

                bantu = bantu->next;
            } while (bantu != NULL);
        }else{
            d=tail->nilaiX;
            head=tail=NULL;
        }

        cout<< d << " terhapus";
    } else cout<<"Stack masih kosong\n";
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
        cout <<"Stack masih kosong\n";
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
        cout<<" = 1. PUSH                  ="<<endl;
        cout<<" = 2. POP                   ="<<endl;
        cout<<" = 3. Tampil Data           ="<<endl;
        cout<<" = 4. Exit                  ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: system("CLS");{
                cout<<"Masukan Data 1 = ";cin>>databaru1;
                insertBelakang(databaru1);
                break;
            }
            case 2: system("CLS");{
                deleteBelakang();
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