#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct todolist
{
    int id;
    string task;
};
int ID;
 void banner();
 void addtask();
 void showtask();
 int searchtask();
 void deletetask();
int main()
{
    while(true)
    {
        banner();
        cout<<"\n\t 1.Add Task";
        cout<<"\n\t 2.Show Task";
        cout<<"\n\t 3.Search Task";
        cout<<"\n\t 4.Delete Task";
        cout<<"\n\t 5.exit";
        int choice;
        cout<<"\nEnter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1:addtask();
                break;
            case 2: 
                showtask();
                break;
            case 3: 
                searchtask();
                break;
            case 4: 
                deletetask();
                break;
            case 5:
                return 0;
            default:
                cout<<"invalid input\n";
                break;
        }
    }
    return 0;
}
void banner()
{
    cout<<"__________________________________"<<endl;
    cout<<"            MY TODO         "<<endl;
    cout<<"__________________________________"<<endl;
}
void addtask()
{
    system("cls");
    banner();
    todolist todo;
    cout<<"enter the new task:"<<endl;
    cin.get();
    getline(cin,todo.task);
    char save;
    cout<<"do you want to save? (y/n)";
    cin>>save;
    if(save=='y')
    {
        ID++;
        ofstream fout;
        fout.open("todo.txt",ios::app);
        fout<<"\n"<<ID<<".";
        fout<<todo.task;
        fout.close();

        char more;
        cout<<"\nAdd more task? (y/n)";
        cin>>more;
        if(more=='y')
        addtask();
        else
        {
            system("cls");
            cout<<"Added task successfully"<<endl;
            return;
        }
    }
    system("cls");

}
void showtask()
{
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt",ios::app);
    cout<<"Task:"<<endl;
    while(!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.task!=" ")
        {
            cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
        }
        else
        cout<<"empty"<<endl;
    }
    fin.close();
    char exit;
    cout<<"exit?(y/n)";
    cin>>exit;
    if(exit!='y')
    {
        showtask();
    }
    system("cls");
}
int searchtask(){
    system("cls");
    banner();
    int id;
    cout<<"enter the ask id";
    cin>>id;
    todolist todo;
    ifstream fin("todo.txt");
    while(!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.id==id)
        {
            system("cls");
            cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
            return id;
        }
    }
    system("cls");
    cout<<"not found"<<endl;
    return 0;
}
void deletetask(){
    system("cls");
    int id=searchtask();
    if(id!=0)
    {
        char del;
        cout<<"delete?(y/n):";
        cin>>del;
        if(del=='y'){
            todolist todo;
            ofstream tempFile;
            tempFile.open("temp.txt");
            ifstream fin;
            fin.open("todo.txt");
            int index=1;
            while(!fin.eof())
            {
                fin>>todo.id;
                fin.ignore();
                getline(fin,todo.task);
                if(todo.id!=id)
                {
                    tempFile<<"\n"<<index;
                    tempFile<<"\n"<<todo.task;
                    index++;
                    ID--;
                }
            }
            fin.close();
            tempFile.close();
            remove("todo.txt");
            rename("temp.txt","todo.txt");
            system("cls");
            cout<<"\n\t Deleted successfully!"<<endl;   
        }
        else{
            system("cls");
            cout<<"not deleted\n";
        }
    }
}