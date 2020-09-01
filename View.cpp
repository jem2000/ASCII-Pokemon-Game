//
// Created by justi on 11/23/2019.
//

#include "View.h"
#include "Input_Handling.h"

View::View() : grid()
{
    size = 11;
    scale = 2;
    origin = Point2D(0,0);
}

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
    try {
        Vector2D Vector = (location - origin) / scale;
        out_x = static_cast<int>(Vector.x);
        out_y = static_cast<int>(Vector.y);
        if (out_x > view_maxsize || out_y > view_maxsize) {
            throw Invalid_Input("Object is outside of the display.");
        } else
            return true;
    }
    catch(Invalid_Input& except)
    {
        cout << "ERROR: " << except.msg_ptr << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
}

void View::clear()
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
                grid[i][j][0] = '.';
                grid[i][j][1] = ' ';
        }
    }
}
void View::Plot(GameObject * ptr)
{
    int x = 0, y = 0;
    bool Subscripts = GetSubscripts(x, y, ptr->GetLocation());
    GetSubscripts(x, y, ptr->GetLocation());
    if (Subscripts) {
        if (grid[x][y][0] != '.') {
            grid[x][y][0] = '*';
            grid[x][y][1] = ' ';
        }
        else
        {
            char *charPtr = new char;
            ptr->DrawSelf(charPtr);
            // if (ptr->ShouldBeVisible()) {
                grid[x][y][0] = *charPtr;
                grid[x][y][1] = *(charPtr + 1);
            /* }
            else
            {
                grid[x][y][0] = '.';
                grid[x][y][1] = ' ';
            } /**/
            delete charPtr;
        }
    }
}
void View::Draw()
{
    for (int i = size; i >= 0; i--) {
        if (i % 2 == 0) {
                cout << i * scale;
                if (i * scale <= 9)
                    cout << " ";
        }
        else cout << "  ";

        for (int j = 0; j < size; j++) {
            cout << grid[j][i][0];
            cout << grid[j][i][1];
        }
        cout << endl;
    }
    cout << "  ";
    for (int k = 0; k < size; k++)
    {
        if (k % 2 == 0)
        {
            cout << k * scale;
            if (k * scale <= 9)
                cout << " ";
        }
        else if (k % 2 == 1)
            cout << "  ";
    }
    cout << endl;
}