#pragma once

const int MAX_ITEMS = 5;

struct Item {
    int x, y;
    char name[20];
    bool active;
    bool isKey; // si es la llave para ganar
};

void initItem(Item* item, int x, int y, const char* name, bool isKey);
