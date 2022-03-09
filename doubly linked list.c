// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int input;//kosongan untuk input input
    struct Node* next;//pointer untuk node selanjutnya
    struct Node* prev;//pointer untuk node sebelumnya
};
int main(){
char pilih;
    struct Node* head = NULL;//Node head yang tidak mempunyai nilai /NULL
    beginning(&head);//eksekusi ke void beginning dengan mengirim &head 
    display(head);//menampilkan node
    insertafter(head);
    display(head);//menampilkan node
    ending(&head);//eksekusi ke void ending dengan mengirim &head
    display(head);//menampilkan node
    printf("\ndelete index 2? Y/N=");
    scanf(" %c", &pilih);
    if(pilih=='Y'||pilih=='y'){
    deleteNode(&head, head->next->next);//pengapusan node pada index 2
    getchar();
    printf("\n index 2 berhasil didelete\n");
    }
    else printf("anda tidak menghapus index ke 2\n");
    display(head);//menampilkan node
}

void display(struct Node* node){
    while (node!=NULL){//jika node tidak sama null maka
    printf("%d ",node->input);//perulangan untuk menamilkan nilai input dari node
    node = node->next;
    }
}
void beginning(struct Node** head_ref){
  char choice='Y';
  int new_input;
    while(choice=='Y'||choice=='y'){//perulangan untuk input data
    printf("begin=");
    scanf("%d",&new_input);
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));//membuat alokasi node
    new_node->input=new_input;//nilai new_input dimasukkan ke input dari new node
    new_node->next=(*head_ref);//next dari new_node adalah *head_ref 
    new_node->prev=NULL;//new node pada prev tidak mempunyai nilai(null)
 
    if((*head_ref)!=NULL)//jika head tidak sama dengan null 
    (*head_ref)->prev=new_node;//ganti prev dari *head_ref menjadi new_node
    (*head_ref)=new_node;//setiap ada node baru akan menjadi *head_ref
    printf("again?Y/N=");
    scanf(" %c",&choice);
    getchar();
    }
}
void ending(struct Node** head_ref){
    int new_input;
    char choice='Y';
    while(choice=='Y'||choice=='y'){//perulangan  untuk input data
    printf("\nending=");
    scanf("%d",&new_input);
   struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));//membuat alokasi node
    struct Node *last =*head_ref;
    new_node->input=new_input;//nilai new_input dimasukkan ke input dari new_node
    new_node->next=NULL;//next dari new_node tidak mempunyai nilai (NULL)
    if(*head_ref==NULL){//jika head_ref tidak mempunyai nilai maka head ref menjadi new_node 
        new_node->prev=NULL;
        *head_ref=new_node;
        return;
    }
        while (last->next!= NULL){//perulangan untuk memindahkan node sampai akhir
        last =last->next;
          }
    
    last->next=new_node;//ubah next menjadi last node
    new_node->prev=last;//Jadikan last sebagai prev dari new_node
    printf("again?Y/N=");
    scanf(" %c",&choice);
}
}
void insertafter(struct Node* prev_node){
        int new_input;
        char choice='y';
    if (prev_node == NULL){//jika prev node tidak memiliki nilai maka return
        printf("nope");
        return;
    }
        while(choice=='Y'||choice=='y'){//perulangan input dara
    struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));//membuat alokasi new_node
    printf("\ninsert after begin=");
    scanf("%d",&new_input);
    new_node->input=new_input;//nilai dari new_input diberikan ke input dari new_node
    new_node->next=prev_node->next;//lanjutan next dari_new_Node adalah next dari prev_node
    prev_node->next=new_node;//lanjutan next dari prev_node adalah new_node
    new_node->prev=prev_node;//sambungkan prev dari new_node ke prev_node
    if(new_node->next!=NULL)//jika next dari new_node tidak sama dengan null maka
    new_node->next->prev=new_node;//ubah prev dari new_node ke new_node berikutnya
    printf("again?Y/N=");
    scanf(" %c",&choice);
        getchar();
        
    } 
}
void deleteNode(struct Node** head,struct Node* deleteNode_node){
    if(*head==NULL||deleteNode_node==NULL)//jika head dan deleteNode_node tidak memiliki nilai maka return
        return;
    if(deleteNode_node->prev!=NULL)//jika prev dari deleteNode_node tidak sama dengan null
        deleteNode_node->prev->next=deleteNode_node->next;//jika bukan node pertama maka dapat menghapus node berikutnya
      free(deleteNode_node);
}
