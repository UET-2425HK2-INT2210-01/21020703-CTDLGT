#include <iostream>
#include <string>

using namespace std;

struct Sinhvien {
    long long ID;
    string Name;
    string Class;
    int check = 0;
};

long long hashfunction(long long id) {
    return (id + 12) % 97;
}

long long stringToLL(const string& str) {
    long long num = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}

void Insert(Sinhvien ht[], long long id, string name, string clas) {
    long long Index = hashfunction(id);
    Sinhvien newsv;
    newsv.ID = id;
    newsv.Name = name;
    newsv.Class = clas;
    newsv.check++;

    if (ht[Index].check == 0)
        ht[Index] = newsv;
    else {
        for (int i = (Index + 1) % 97; i != Index; i = (i + 1) % 97) {
            if (ht[i].check != 1) {
                ht[i] = newsv;
                break;
            }
        }
    }
}

string Infor(Sinhvien ht[], long long id) {
    long long Index = hashfunction(id);
    if ((ht[Index].check == 1) && (ht[Index].ID == id))
        return ht[Index].Name + "," + ht[Index].Class;
    else {
        for (int i = (Index + 1) % 97; i != Index; i = (i + 1) % 97) {
            if (ht[i].check == 1 && ht[i].ID == id)
                return ht[i].Name + "," + ht[i].Class;
        }
        return "NA,NA";
    }
}

void Delete(Sinhvien ht[], long long id) {
    long long Index = hashfunction(id);
    if ((ht[Index].check == 1) && (ht[Index].ID == id))
        ht[Index].check = 0;
    else {
        for (int i = (Index + 1) % 97; i != Index; i = (i + 1) % 97) {
            if ((ht[i].check == 1) && (ht[i].ID == id))
                ht[i].check = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    Sinhvien* ht = new Sinhvien[97];
    string s;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        getline(cin, s);
        string a = s.substr(0, 6);

        if (a == "Insert") {
            long long id = stringToLL(s.substr(7, s.find(",") - 7));
            s[s.find(",")] = '.';
            string name = s.substr(s.find(".") + 1, s.find(",", s.find(".") + 1) - s.find(".") - 1);
            string clas = s.substr(s.find(",", s.find(".") + 1) + 1, s.find(')') - s.find(",", s.find(".") + 1) - 1);
            Insert(ht, id, name, clas);
        } else if (a == "Infor(") {
            long long id = stringToLL(s.substr(6, s.find(")") - 6));
            cout << Infor(ht, id) << "\n";
        } else {
            long long id = stringToLL(s.substr(7, s.find(")") - 7));
            Delete(ht, id);
        }
    }

    delete[] ht;
    return 0;
}

