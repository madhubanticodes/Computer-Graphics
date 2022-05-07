#include<iostream.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

const int size = 4;

void bezier(int x[], int y[]) {
  int gr = DETECT, gm;
  initgraph(&gr, &gm, (char*)"C:\\TURBOC3\\BGI");
  double put_x, put_y;
  cout<<"\nTHE REQUIRED CURVE:";

  for(int i = 0; i < size; i++) {
    putpixel(x[i], y[i], 3);
    delay(1);
  }

  for(double t = 0; t <= 1; t += 0.001) {
    put_x = pow(1 - t, 3) * x[0] + 3 * t * pow(1-t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];

    put_y = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];

    putpixel(put_x, put_y, WHITE);
    delay(1);
  }
}

void hermite(int x[], int y[]) {
  int gr = DETECT, gm;
  initgraph(&gr, &gm, (char*)("C:\\TURBOC3\\BGI"));
  double put_x, put_y;
  cout<<"\nTHE REQUIRED CURVE:";

  for(int i = 0; i < size; i++) {
    putpixel(x[i], y[i], 3);
    delay(1);
  }

  for(double t = 0; t <= 1; t += 0.001) {
    put_x = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * x[0] + (-2 * pow(t, 3) + 3 * pow(t, 2)) * x[1] + (pow(t, 3) - 2 * pow(t, 2) + t) * x[2] + (pow(t, 3) - pow(t, 2)) * x[3] ;

    put_y = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * y[0] + (-2 * pow(t, 3) + 3 * pow(t, 2)) * y[1] + (pow(t, 3) - 2 * pow(t, 2) + t) * y[2] + (pow(t, 3) - pow(t, 2)) * y[3];

    putpixel(put_x, put_y, WHITE);
    delay(1);
  }
}

int main() {
  int x[4], y[4];
  int choice;

  cout<<"\n====================================================================\n";
  cout<<"\t\tHERMITE/BEZIER CURVE (USING 4 CONTROL POINTS)";
  cout<<"\n====================================================================";

  do {
    cout<<"\nChoose any curve of your choice:";
    cout<<"\n1. BEZIER CURVE";
    cout<<"\n2. HERMITE CURVE";
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch(choice) {
      case 1 : {
	cout<<"\nEnter the control points:-\n";
	for(int i = 0; i < size; i++) {
	  cout<<"x"<<i<<": ";
	  cin>>x[i];
	  cout<<"y"<<i<<": ";
	  cin>>y[i];
	}
	bezier(x, y);
      }
      break;
      case 2 : {
	cout<<"\nEnter the control points:-\n";
	for(int i = 0; i < size; i++) {
	  cout<<"x"<<i<<": ";
	  cin>>x[i];
	  cout<<"y"<<i<<": ";
	  cin>>y[i];
	}
	hermite(x, y);
      }
      break;
      default : cout<<"Please enter a valid input!";
    }
    cout<<"\nDo you want to continue?";
    cin>>choice;
  }while(choice=='y' || choice=='Y');
  getch();
  closegraph();
  return 1;
}
