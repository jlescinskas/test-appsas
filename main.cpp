/*#include <iostream>
#include <windows.h>
#include <mmsystem.h>
//#include <mciapi.h>
using namespace std;

int main()
{
    mciSendString("open \"*.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
    //PlaySound(TEXT("music.mp3"), NULL, SND_FILENAME | SND_SYNC);

    return 0;
}*/


/*#include <iostream>
#include <thread>

using namespace std;

void task1()
{
    for(int i = 0; i < 10; i++) {
    cout << "labas" << endl;
  }
}

int main(){
  thread t1(task1);

  for(int i = 0; i < 10; i++) {
    cout << i << endl;
  }

  t1.join();
  return 0;
}*/

/*#include <iostream>

using namespace std;

int main()
{
  //SetConsoleOutputCP(CP_UTF8);
  system("Color 1")
    cout << R"(
           .--._.--.
          ( O     O )
          /   . .   \
         .`._______.'.
        /(           )\
      _/  \  \   /  /  \_
   .~   `  \  \ /  /  '   ~.
  {    -.   \  V  /   .-    }
_ _`.    \  |  |  |  /    .'_ _
>_       _} |  |  | {_       _<
 /. - ~ ,_-'  .^.  `-_, ~ - .\
         '-'|/   \|`-`)" << '\n';

	return 0;
}*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//c++ thread simple (suletes)

// sukaiciuoti procentus laimejimo, kad but tikslensi rezulatats


char aha ='X';  // sitas sudas eis visur

int randRage (int low, int high)
{
    return rand() % (high-low)+ low;
}

void printArray (char arr[24])
{
    for(int i=0; i<=24; i++)
    {
        if (arr[i]!='X'&& arr[i]!='O' && arr[i]!='Y')
        {
            cout <<'32';
        }
        if(i%5==0)
        {
            cout <<'32';
            cout <<endl;
            cout <<"+------------------+"<<endl;
            cout <<"|";
            if(arr[i]!='X'&& arr[i]!='O')
            {
                cout <<'32';
            }
        }
        cout <<arr[i]<<'32';
        cout <<"|"<<'32';
    }
    cout <<endl;
    cout <<"+------------------+";
    cout <<endl;
}

void results(int ind, int scr, int mov)
{
    cout <<"indicator now is: "<<ind <<endl;
    cout <<"your score now is: "<<scr<<endl;
    cout <<"left moves: "<<mov<<endl;
}

int main()
{
    int indicator=0, leftMoves=21;
    char move;
    int score=0;
    char arr[24]= {};
    srand (time(NULL));
    int galinis=0;
    for(int i=0; i<25; i++)
    {
        int naujas =randRage(1, 24);
        galinis =randRage(20,24);
        if(naujas%3==0||naujas%4==0)
        {
            arr[i]='O';
        }
    }
    arr[indicator]=aha;
    arr[galinis]='Y';
    //cout <<"Your goal is from X to Y score as many points as you can without redoing the same move"<<endl;
    //cout <<"You can move with keys -A- (left) -W- (up) -S- (down) -D- (right)"<<endl;
    // cout <<"Game board is yours now;)"<<endl;
    printArray(arr);
    cout <<endl;
    for(int i=0; i<22; i++)
    {
        cin >>move;
        if(move=='D')
        {
            indicator++;
            if(arr[indicator]=='O')
            {
                score++;
            }
            if(arr[indicator]=='Y')
            {
                cout <<"-------------------------------------------------"<<endl;
                cout <<"you finished this scrappy game, final score is: "<<score<<endl;
                cout <<"-------------------------------------------------"<<endl;

                break;
            }
            if(indicator%5==0)
            {
                indicator--;
                leftMoves--;
                cout <<"---------------"<<endl;
                cout <<"negali eit ten"<<endl;
                cout <<"left moves: "<<leftMoves<<endl;
                cout <<"---------------"<<endl;
                printArray(arr);
            }
            if(arr[indicator]==aha)
            {
                cout <<"-------------------------------------------------"<<endl;
                cout <<"GAME OVER"<<endl;
                cout <<"-------------------------------------------------"<<endl;
                break;
            }
            else
            {
                arr[indicator]=aha;
                printArray(arr);
                leftMoves--;
                results(indicator, score, leftMoves);
            }
        }


        else if (move =='A')
        {
            indicator--;
            if(arr[indicator]==aha|| indicator<0)
            {
                cout <<"-------------------------------------------------"<<endl;
                cout <<"GAME OVER"<<endl;
                cout <<"-------------------------------------------------"<<endl;
                break;
            }
            if(arr[indicator]=='O')
            {
                score++;
            }
            if(indicator==4 || indicator==9||indicator==14||indicator==19||indicator==24)
            {
                leftMoves--;
                cout <<"---------------"<<endl;
                cout <<"negali eit ten"<<endl;
                cout <<"left moves: "<<leftMoves<<endl;
                cout <<"---------------"<<endl;
                printArray(arr);
            }
            if(arr[indicator]=='Y')
            {
                cout <<"-------------------------------------------------"<<endl;
                cout <<"you finished this scrappy game, final score is: "<<score<<endl;
                cout <<"-------------------------------------------------"<<endl;

                break;
            }
            arr[indicator]=aha;
            printArray(arr);
            leftMoves--;
            results(indicator, score, leftMoves);
        }
        else if(move =='W')
        {
            if(indicator<5)
            {
                cout <<"-------------------------------------------------"<<endl;
                cout <<"GAME OVER"<<endl;
                cout <<"-------------------------------------------------"<<endl;
                break;
            }
            else indicator =indicator-5;
            if(arr[indicator]=='O')
            {
                score++;
            }
            if(arr[indicator]=='Y')
            {
                cout <<"-------------------------"<<endl;
                cout <<"you finished this scrappy game, final score is: "<<score<<endl;
                cout <<"-------------------------------------------------"<<endl;

                break;
            }
            arr[indicator]=aha;
            printArray(arr);
            leftMoves--;
            results(indicator, score, leftMoves);
        }
        else if (move =='S')
        {
            if (indicator>19)
            {
                cout <<"-------------------------------------------------"<<endl;
                cout <<"GAME OVER"<<endl;
                cout <<"-------------------------------------------------"<<endl;
                break;
            }

            else indicator=indicator+5;
            if(arr[indicator]=='O')
            {
                score++;
            }
            if(arr[indicator]=='Y')
            {
                cout <<"-------------------------------------------------"<<endl;

                cout <<"you finished this scrappy game, final score is: "<<score<<endl;
                cout <<"-------------------------------------------------"<<endl;

                break;
            }
            arr[indicator]=aha;
            printArray(arr);
            leftMoves--;
            results(indicator, score, leftMoves);
        }
        else if (move!='S'&& move!='A'&&move!='W'&&move!='D')
        {
            cout <<"----------------------------------"<<endl;
            cout <<"you can't play with those keys, try again:)"<<endl;
            leftMoves--;
            cout <<"left moves: "<<leftMoves<<endl;
            cout <<"----------------------------------"<<endl;

        }

    }


    return 0;
}

