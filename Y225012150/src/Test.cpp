/** 
* @file Test.cpp
* @description Programı çalıştıran ana kaynak dosyasıdır. Oluşturulan classları kullanarak istenen sonucu vermek için Veri.txt'den verileri okuyup
* her satırı bir AVL ağacına kaydeden daha sonrasında bu AVL ağacında dolanıp gerekli şekilde yığıtlar oluşturan ve min max değerlerine göre
* istenem somucu veren kaynak dosyasıdır. 
* @course 2.Öğretim B grubu
* @assignment 2.Ödev
* @date Kodu 09.12.2023
* @author Sena Aslıbay/sena.aslibay1@ogr.sakarya.edu.tr
**/




#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "AVL.hpp"
#include "LinkedList.hpp"

using namespace std;

int main()
{
    LinkedList *avl_list = new LinkedList();
    int max_int = 0;
    int min_int = INT32_MAX;
    int sayac = 1;
    int sayi;
    fstream veri("Veri.txt");
    if (veri.is_open())
    {
        string tp;
        string temp_int = "";
        while (getline(veri, tp))
        {
            AVL *avl = new AVL();

            for (int i = 0; i < tp.size(); i++)
            {
                if (tp.at(i) == *" ")
                {
                    avl->Add(stoi(temp_int));
                    avl->SetAvlNo(sayac);
                    temp_int = "";
                }
                else if (i == tp.size() - 1)
                {
                    temp_int += tp.at(i);
                    avl->Add(stoi(temp_int));
                    avl->SetAvlNo(sayac);
                    temp_int = "";
                }
                else
                {
                    temp_int += tp.at(i);
                }
            }
            avl->postorder();
            avl_list->add(avl);
            cout << avl->GetAsciiChar();
            sayac++;
        }
        system("cls");

        Iterator itr;
        while (avl_list->size() != 1)
        {
            itr = avl_list->iterator();
            AVL *avl_min = new AVL();
            AVL *avl_max = new AVL();
            min_int = INT32_MAX;
            max_int = 0;
            while (itr.hasNext())
            {
                AVL *temp_avl = itr.next();
                sayi = temp_avl->getStackTop();
                if (sayi < min_int)
                {
                    min_int = sayi;
                    avl_min = temp_avl;
                }
                if (sayi > max_int)
                {
                    max_int = sayi;
                    avl_max = temp_avl;
                }
            }

            AVL *temp_avl;
            try
            {
                avl_min->popStack();
            }
            catch (const char *thecode)
            {
            }
            if (avl_min->isEmptyStack())
            {
                avl_list->remove(avl_min);
                avl_min->Clear();
                itr = avl_list->iterator();
                while (itr.hasNext())
                {
                    temp_avl = itr.next();
                    temp_avl->refillStack();
                    cout << temp_avl->GetAsciiChar();
                }
                system("cls");
            }
            else
            {
                avl_max->popStack();

                if (avl_max->isEmptyStack())
                {
                    avl_list->remove(avl_max);
                    avl_max->Clear();
                    itr = avl_list->iterator();
                    while (itr.hasNext())
                    {
                        temp_avl = itr.next();
                        temp_avl->refillStack();
                        cout << temp_avl->GetAsciiChar();
                    }
                    system("cls");
                }
            }
        }
        system("cls");
        cout << endl
             << "==============================" << endl;
        cout << "|                            |" << endl;
        cout << "|                            |" << endl;
        cout << "|     Son Karakter: " << avl_list->first()->GetAsciiChar() << "        |" << endl;
        cout << "|     AVL No      : " << avl_list->first()->getAvlNo() << "      |" << endl;
        cout << "|                            |" << endl;
        cout << "|                            |" << endl;
        cout << "==============================" << endl;
    }
}