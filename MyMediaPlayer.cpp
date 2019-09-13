
 /*
 OJECTIVE          :  C++ Program to Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  ALL FUNCTIONING OF A MEDIA PLAYER.
 APPROACH:         :  Circular Doubly Linked List IS USED TO IMPLEMENT THE WHOLE FUNCTIONING OF MEDIA PLAYER.
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
using namespace std;
 
/*
 * songlist Declaration
 */
struct songlist
{
    string title, singer;
    int length;
    string gener;
    struct songlist *next;
    struct songlist *prev;
    int info;
};
int counter = 0;
/*
 * Class Declaration
 */
class double_clist
{
songlist *start;
songlist *last;
songlist *curr;

    public:
        songlist *create_songlist(string title, string singer, string gener, int length);
        void insert_begin(string title, string singer, string gener, int length);
        void playsong();
        void playnext();
        void playprev();
       // void getdata();
        void insert_last(string title, string singer, string gener, int length);
        void insert_pos(string title, string singer, string gener, int length);
        void delete_pos();
        void search();
        void update();
        void display();
        void reverse();
        void sort();
        double_clist()
        {
            start = NULL;
            last = NULL;			
        }
};;
 
/*
 * 
 /*
 OJECTIVE          :  C++ Program to Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  ALL FUNCTIONING OF A MEDIA PLAYER.
 APPROACH:         :  Circular Doubly Linked List IS USED TO IMPLEMENT THE WHOLE FUNCTIONING OF MEDIA PLAYER.
 */
int main()
{
    int choice;
    double_clist cdl;
    string tit, gen, sin;
	int len;
    while (1)
    {
        cout<<"\n-------------------------------"<<endl;
        cout<<"-----------MEDIA PLAYER ------------"<<endl;
        cout<<"\n-------------------------------"<<endl;         
        cout<<"1.play current song " <<endl;
        cout<<"2.play next song "<<endl;
        cout<<"3.play previous song "<<endl;
        cout<<"4.Insert a Song at Last"<<endl;
        cout<<"5.Insert a Songat Position"<<endl;
        cout<<"6.Delete a Song at Position"<<endl;
        cout<<"7.Update songlist"<<endl;
        cout<<"8.Search a Song"<<endl;
        cout<<"9.Sort"<<endl;
        cout<<"10.Display PlayList"<<endl;
        cout<<"11.Reverse PlayList"<<endl;
        cout<<"12.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
       
        case 1:
            	cdl.playsong();
            	break;
        case 2:
        		cdl.playnext();
        		break;
        case 3:
        		cdl.playprev();
        		break;
        case 4:
			cout<<"ENTER TITLE OF THE SONG: "<<endl;
        	cin.ignore();
			getline(cin,tit,'\n');
        	cout<<"ENTER SINGER OF THE SONG: "<<endl;
        	cin.ignore();
			getline(cin,sin,'\n');
        	cout<<"ENTER GENER OF THE SONG: "<<endl;
         	cin.ignore();
			getline(cin,gen,'\n');
        	cout<<"ENTER LENGTH OF THE SONG: "<<endl;
        	cin>>len;
			cdl.insert_last(tit,sin,gen,len);
            break;   
        case 5:
        	cout<<"ENTER TITLE OF THE SONG: "<<endl;
        	cin.ignore();
			getline(cin,tit,'\n');
        	cout<<"ENTER SINGER OF THE SONG: "<<endl;
        	cin.ignore();
			getline(cin,sin,'\n');
        	cout<<"ENTER GENER OF THE SONG: "<<endl;
         	cin.ignore();
			getline(cin,gen,'\n');
        	cout<<"ENTER LENGTH OF THE SONG: "<<endl;
        	cin>>len;
            cdl.insert_pos(tit,sin,gen,len);
            break; 
        case 6:
            cdl.delete_pos();
            break;
        case 7:
            cdl.update();
            break;
        case 8:
            cdl.search();
            break;
        case 9:
            cdl.sort();
            break;
        case 10:
            cdl.display();
            break;
        case 11:
            cdl.reverse();
            break;
        case 12:
            exit(1); 
        default:
            cout<<"Wrong choice"<<endl;	
        }
    }
    return 0;
}
 
/*
 *MEMORY ALLOCATED FOR songlist DYNAMICALLY
 
 
 */
 
 
 
 /*
 OJECTIVE          :  C++ function to play Music in music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  palying a song which is listed in A MEDIA PLAYER.
 APPROACH:         :  Circular Doubly Linked List IS USED TO PLAY A SONG WHICH IS IN MEDIA PLAYER.
*/
 	void double_clist::playsong()

{
	if (start == last && start == NULL)
    {
        cout<<"SORRY ! PLAYLIST IS EMPTY. NOTHING TO PLAY"<<endl;
        return;
    }
	struct songlist *s;
	s=start;	
	cout<<"currently playing "<<s->title;
	curr=s;
}
void double_clist::playnext()
{
	if (start == last && start == NULL)
    {
        cout<<"SORRY ! PLAYLIST IS EMPTY. NOTHING TO PLAY"<<endl;
        return;
    }
	struct songlist *st;
	st=curr;
	st=st->next;
	cout<<" currenyly playing "<<st->title;
	
}
void double_clist::playprev()
{
	if (start == last && start == NULL)
    {
        cout<<"SORRY ! PLAYLIST IS EMPTY. NOTHING TO PLAY"<<endl;
        return;
    }
	struct songlist *sp;
	sp=curr;
	sp=sp->prev;
	cout<<" currenyly playing "<<sp->title;
	
}
songlist* double_clist::create_songlist(string title, string singer, string gener, int length)
{
    counter++;  
    struct songlist *temp;
    temp = new(struct songlist);
    temp->title = title;
    temp->singer = singer;
    temp->gener=gener;
    temp->length=length;
    temp->prev = NULL;
    return temp;
}
/*
 *INSERTS ELEMENT AT BEGINNING
 */
 /*
 OJECTIVE          :  C++ Program to insert a music in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  string : title,gener,singer
 					  int    : length
 OUTPUT PARAMETER  :  INSERTION OF A SONG IN MEDIA PLAYER AT BEGINING.
 APPROACH:         :  Circular Doubly Linked List IS USED TO INSERT  A SONG IN MEDIA PLAYER AT BEGINING
*/
void double_clist::insert_begin(string title, string singer, string gener, int length)
{

    struct songlist *temp;
    temp = create_songlist(title, singer, gener, length);
    if (start == last && start == NULL)
    {    
        cout<<"SONG ADDED INTO EMPTY PLAYLIST"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
        start->prev = last;
        last->next = start;
        cout<<"SONG SUCCESSFULLY ADDED AT THE BEGINNING "<<endl;
    }
}
 
/*
 *INSERTS ELEMNET AT LAST
 */
  /*
 OJECTIVE          :  C++ Program to insert a music in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  string : title,gener,singer
 					  int    : length
 OUTPUT PARAMETER  :  NONE
 APPROACH:         :  Circular Doubly Linked List IS USED TO INSERT  A SONG IN MEDIA PLAYER AT LAST
*/
void double_clist::insert_last(string title, string singer, string gener, int length)
{
 
    struct songlist *temp;
    temp = create_songlist(title, singer, gener, length);
    if (start == last && start == NULL)
    {
        cout<<"SONG ADDED INTO EMPTY PLAYLIST "<<endl;
        start = last = temp;
        start->next = last->next = NULL;    
        start->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        start->prev = last;
        last->next = start;
        cout<<"SONG SUCCESSFULLY ADDED AT THE END "<<endl;

    }
}
/*
 *INSERTS ELEMENT AT POSITION
 */
 
   /*
 OJECTIVE          :  C++ Program to insert a music in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  string : title,gener,singer
 					  int    : length
 OUTPUT PARAMETER  :  NONE
 APPROACH:         :  Circular Doubly Linked List IS USED TO INSERT  A SONG IN MEDIA PLAYER AT A GIVEN POSTION
*/
void double_clist::insert_pos(string title, string singer, string gener, int length)
{    
    int value, pos, i;

    cout<<endl<<"ENTER POSITION WHERE YOU WANT TO INSERT THE SONG: "<<endl;
    cin>>pos;
    struct songlist *temp, *s, *ptr;
    temp = create_songlist(title, singer, gener, length);
    if (start == last && start == NULL)
    {
        if (pos == 1)
        {
            start = last = temp;
            start->next = last->next = NULL;    
            start->prev = last->prev = NULL;
        }
        else
        {
            cout<<" POSITION IS OUT OF THE RANGE"<<endl;
            counter--;
            return;
        }
    }  
    else
    {
        if (counter < pos)
        {
             cout<<"POSITION IS OUT OF THE RANGE "<<endl;
             counter--;
             return;   		
        }
        s = start;		
        for (i = 1;i <= counter;i++)
        {
            ptr = s;
            s = s->next;
            if (i == pos - 1)
            {
                ptr->next = temp;
                temp->prev = ptr;
                temp->next = s;
                s->prev = temp;
                cout<<"SONG ADDED SUCCESSFULLY AT THE GIVEN POSITION"<<endl;
                break;
            }
        }
    }
}
/*
 * Delete songlist at Particular Position
 */
   /*
 OJECTIVE          :  C++ Program to delete a music in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  NONE
 APPROACH:         :  Circular Doubly Linked List IS USED TO DELETE A SONG IN MEDIA PLAYER.
*/
 	
void double_clist::delete_pos()
{    
    int pos, i;
    songlist *ptr, *s;
    if (start == last && start == NULL)
    {
        cout<<"SORRY ! PLAYLIST IS EMPTY. NOTHING TO DELETE"<<endl;
        return;
    }
    cout<<endl<<"ENTER THE INDEX OF THE SONG YOU WANT TO DELETE "<<endl;
    cin>>pos;
    if (counter < pos)
    {
        cout<<" INDEX OUT OF RANGE"<<endl;
        return;
    }
    s = start;
    if(pos == 1)
    {
        counter--;
        last->next = s->next;
        s->next->prev = last;
        start = s->next;
        free(s);
        cout<<"YOUR SONG HAS BEEN DELETED "<<endl;
        return;	   
    }
    for (i = 0;i < pos - 1;i++ )
    {  
        s = s->next;
        ptr = s->prev;    	  
    }    
    ptr->next = s->next;
    s->next->prev = ptr;
    if (pos == counter)
    {
        last = ptr; 	   
    }
    counter--;
    free(s);
    cout<<"YOUR SONG HAS BEEN DELETED "<<endl;
}
/*
 * Update value of a particular songlist 
 */
 
   /*
 OJECTIVE          :  C++ Program to updatea music in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  NONE
 APPROACH:         :  Circular Doubly Linked List IS USED TO UPDATE  A SONG IN MEDIA PLAYER AT LAST
*/
void double_clist::update()
{
    int value, i, pos,length;
    string title, singer, gener;
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to update"<<endl;
        return; 
    }
    cout<<endl<<"Enter the postion of songlist to be updated: ";
    cin>>pos;
      cout<<"ENTER TITLE OF THE SONG: "<<endl;
        	cin.ignore();
			getline(cin,title,'\n');
		    cout<<"ENTER SINGER OF THE SONG: "<<endl;
        	cin.ignore();
			getline(cin,title,'\n');
        	cout<<"ENTER GENER OF THE SONG: "<<endl;
        	cin.ignore();
			getline(cin,title,'\n');
        	cout<<"ENTER LENGTH OF THE SONG: "<<endl;
        	cin>>length;
    struct songlist *s;
    if (counter < pos)
    {
        cout<<"POSITION OUT OF RANGE"<<endl;
        return;
    }
    s = start;  
    if (pos == 1)
    {
       s->singer=title;
       s->title=singer;
       s->gener=gener;
       s->length=length;
       cout<<"PLAYLIST SUCCESSFULLY UPDATED"<<endl;
       return;   
    }
    for (i=0;i < pos - 1;i++)
    {
        s = s->next; 		 
    }
      // s->info = value;
       s->singer=singer;
       s->title=title;
       s->gener=gener;
       s->length=length;
    cout<<"PLAYLIST SUCCESSFULLY UPDATED"<<endl;
}
/*
 * Search Element in the list
 */
 
   /*
 OJECTIVE          :  C++ Program to search a music in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  NONE
 APPROACH:         :  Circular Doubly Linked List IS USED TO SEARCH  A SONG IN MEDIA PLAYER AT LAST
*/
void double_clist::search()
{
    int pos = 0, i;
    string sname;
    bool flag = false;
    struct songlist *s;
    if (start == last && start == NULL)
    {
        cout<<"PLAYLIST IS EMPTY . NOTHING TO SEARCH"<<endl;
        return;
    }
    cout<<endl<<"ENTER THE SONG YOU WANT TO SEARCH ";
    cin>>sname;
    s = start;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->title == sname)
        {
            cout<<"SONG  "<<s->title<<" FOUNT AT POSITION "<<pos<<endl;
            flag = true;
        }    
        s = s->next;
    }
    if (!flag)
        cout<<"SONG NOT FOUND IN THE PLAYLIST "<<endl;   
}
/*
 * Sorting Doubly Circular Link List
 */  /*
 OJECTIVE          :  C++ Program to sort a music in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  NONE
 APPROACH:         :  Circular Doubly Linked List IS USED TO SORT MUSIC  IN MEDIA PLAYER AT LAST
*/
void double_clist::sort()
{
    struct songlist *temp, *s;
    string value;
	int i,value_l;
    if (start == last && start == NULL)
    {
        cout<<"PLAYLIST IS EMPTY. NOTHING TO SORT "<<endl;
        return;
    }
    s = start;
    for (i = 0;i < counter;i++)
    {
        temp = s->next;
        while (temp != start)
        {
            if (s->title > temp->title)
            {
                value = s->title;
                s->title = temp->title;
                temp->title = value;
                value=s->singer;
                s->singer=temp->singer;
                temp->singer=value;
                value=s->gener;
                s->gener=temp->gener;
                temp->gener=value;
                value_l=s->length;
                s->length=temp->length;
                temp->length=value_l;
                
            }
            temp = temp->next;
        }
        s = s->next;
    }
}
/*
 * Display Elements of the List 
   /*
 OJECTIVE          :  C++ Program to  display a music in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  NONE
 APPROACH:         :  Circular Doubly Linked List IS USED TO DISPLAY  A SONG IN MEDIA PLAYER AT LAST
*/
void double_clist::display()
{
    int i;
    struct songlist *s;
    if (start == last && start == NULL)
    {
        cout<<"PLAYLIST IS EMPTY . NOTHING TO PLAY "<<endl;
        return;
    }
    s = start;
    cout<<"SONG TITLE \t SINGER NAME \t  SONG GENER \t  SONG LENGTH"<<endl;
    for (i = 0;i < counter-1;i++)
    {	
    
        cout<<s->title<<"\t\t"<<s->singer<<"\t\t"<<s->gener<<"\t\t"<<s->length<<endl;
        s = s->next; 
    }
   		cout<<s->title<<"\t\t"<<s->singer<<"\t\t"<<s->gener<<"\t\t"<<s->length<<endl;
}
/*
 * Reverse Doubly Circular Linked List 
 */
   /*
 OJECTIVE          :  C++ Program to reverse a music list  in Music palyer using Circular Doubly Linked List.
 INPUT PARAMETER   :  NONE
 OUTPUT PARAMETER  :  NONE
 APPROACH:         :  Circular Doubly Linked List IS USED TO REVERSE  A SONG LIST IN MEDIA PLAYER AT LAST
*/
void double_clist::reverse()
{
    if (start == last && start == NULL)
    {
        cout<<"PLAYLIST IS EMPTY "<<endl;
        return;
    }
    struct songlist *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != start)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    last = start;
    start = p1;
    cout<<"PLAYLIST REVERSED "<<endl; 	 
}

