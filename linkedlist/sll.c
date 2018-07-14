#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}NODE;

void add(NODE **p,int val){
  NODE *newnode = (NODE*)malloc(sizeof(NODE));
  newnode->data = val;
  newnode->next = NULL;

  if(*p == NULL){
    *p = newnode;
  }else{
    NODE *temp = *p;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next = newnode;
  }
}

void display(NODE *p){
  while(p!=NULL){
    printf("%d->",p->data);
    p=p->next;
  }
}

void displayrec(NODE *p){
  if(p==NULL){
    return;
  }
  printf("%d->",p->data);
  displayrec(p->next);
}

void displayrevrec(NODE *p){
  if(p==NULL){
    return;
  }
  displayrevrec(p->next);
  printf("%d->",p->data);
}

int count(NODE *p){
  int count = 0;
  while(p!=NULL){
    count++;
    p=p->next;
  }
  return count;
}

void sortll(NODE *p){
  int n = count(p);
  for(int i=0;i<n-1;i++){
    for(NODE *j=p;j->next!=NULL;j=j->next){
      if(j->data>j->next->data){
        int t = j->data;
        j->data = j->next->data;
        j->next->data = t;
      }
    }
  }
}

int max(NODE *p){
  int maxVal = 0;

  while(p!=NULL){
    if(p->data>maxVal){
      maxVal = p->data;
    }
  }
  return maxVal;
}

void reverse(NODE **p){
  NODE *prev,*curr,*next;
  prev = NULL;
  next = NULL;
  curr = *p;

  while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *p = prev;
}

void reverseRecursive(NODE **p){
  if(*p == NULL){
    return;
  }
  NODE *first = *p;
  NODE *rest = first->next;
  if(rest == NULL){
    return;
  }

  reverseRecursive(&rest);
  first->next->next=first;
  first->next = NULL;
  *p = rest;
}

int delete(NODE **p,int val){
  NODE *temp = *p;
  NODE *prev = NULL;
  while(temp!=NULL){
    if(temp->data == val){
      break;
    }
    prev = temp;
    temp=temp->next;
  }
  if(temp==NULL){
    return 0;
  }
  if(temp==*p){
    *p = (*p)->next;
  }else{
    prev->next = temp-next;
  }
  free(temp);
  return 1;
}

int insertafter(NODE *p,int after,int val){
  while(p!=NULL||p->data!=after){
    p=p->next;
  }
  if(p==NULL){
    return 0;
  }
  NODE *newnode = (NODE*)malloc(sizeof(NODE));
  newnode->data = val;
  newnode->next = p->next;
  p->next = newnode;

  return 1;
}

int insertpos(NODE **p,int pos,int val){
  NODE *newnode = (NODE*)malloc(sizeof(NODE));
  newnode->data = val;
  newnode->next = NULL;

  if(pos == 1){
    newnode->next = *p;
    *p = newnode;
  }else{
    NODE *temp = *p;
    NODE *prev = NULL;
    int i=1;
    while(temp!=NULL||i!=pos){
      i++;
      prev = temp;
      temp=temp->next;
    }
    int c=count(*p);
    if(i == c+1){
      temp->next = newnode;
    }else if(temp == NULL){
      return 0;
    }else{
      newnode->next = temp;
      prev->next = newnode;
    }

  }
  return 1;
}

int ol(NODE **p,int v)

{

    NODE *newnode,*temp,*prev;

    temp=*p;
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=v;
    newnode->next=NULL;

    while(temp!=NULL)

    {
        if(v<temp->data)
        {
            break;
        }
        prev=temp;
        temp=temp->next;
    }

    if(temp==*p)

    {
        newnode->next=*p;
        *p=newnode;
        return 1;
    }

    else

    {
        newnode->next=prev->next;
        prev->next=newnode;
        return 1;
    }

    if(temp==NULL)

    {
        return 0;
    }
}

NODE* intersection(NODE *p1,NODE *p2)
{
    NODE *p3,*t;

    p3=NULL;

    while(p1!=NULL)

    {
        t=p2;

        while(t!=NULL)

        {
            if(p1->data==t->data)

            {
                add(&p3,p1->data);
                break;
            }

            t=t->next;
        }

        p1=p1->next;
    }

    return p3;
}

NODE* nion(NODE *p1,NODE *p2)
{
    NODE *p3,*t;

    p3=NULL;
    t=p1;

    while(p1!=NULL)
	{
		add(&p3,p1->data);
		p1=p1->next;
	}

	while(p2!=NULL)
	{

		p1=t;

		while(p1!=NULL)
		{
			if(p1->data==p2->data)
			{
				break;
			}
			p1=p1->next;
		}

		if(p1==NULL)
        {
			add(&p3,p2->data);
        }

		p2=p2->next;
    }
	return p3;

}

int main()
{

  #ifndef ONLINE_JUDGE
      // for getting input from input.txt
      freopen("input.txt", "r", stdin);
      // for writing output to output.txt
      freopen("output.txt", "w", stdout);
  #endif

    NODE *first=NULL,*second=NULL;

    add(&first,40);
    add(&first,30);
    add(&first,20);
    add(&first,10);

    add(&second,10);
    add(&second,30);
    add(&second,50);
    add(&second,70);

    // display(first);
    //
    // printf("\n\n");
    //
    // display(second);
    //
    // printf("\n\n");
    //
    // displayrec(first);
    //
    // printf("\n");
    //
    // displayrec(second);
    //
    //
    // printf("\n\n");
    //
    // displayrevrec(first);
    //
    // printf("\n");
    //
    // displayrevrec(second);
    //
    // printf("\n");

    display(first);

    printf("\n\n");

    reverseRecursive(&first);

    display(first);

    printf("\n\n");

/*
    NODE*inter=intersection(first,second);
    display(inter);
    NODE* unin=nion(first,second);
    display(unin);
*/
/*
    sort(first);
    display(first);
    int c=count(first);
    printf("number of nodes in linked list is %d\n",c);
    int m=max(first);
    printf("Max value is %d\n",m);
    reverse(&first);
    display(first);
    int d=del(&first,40);
    printf("Result is %d\n",d);
    display(first);
    int ia=insertafter(first, 20, 25);
    printf("Result is %d\n",ia);
    display(first);
    int ip=insertpos(&first,1,35);
    printf("Result is %d\n",ip);
    display(first);
    ip=insertpos(&first,3,55);
    printf("Result is %d\n",ip);
    display(first);
    ip=insertpos(&first,7,75);
    printf("Result is %d\n",ip);
    display(first);
    ip=insertpos(&first,8,95);
    printf("Result is %d\n",ip);
    display(first);
    ip=insertpos(&first,10,115);
    printf("Result is %d\n",ip);
    display(first);
    int o=ol(&first,50);
    printf("Result is %d\n",o);
    display(first);
    o=ol(&first,30);
    printf("Result is %d\n",o);
    display(first);
    o=ol(&first,100);
    printf("Result is %d\n",o);
    display(first);
*/
    return 0;
}
