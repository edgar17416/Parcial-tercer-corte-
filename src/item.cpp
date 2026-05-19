#include "item.h"
#include <cstring>

void initItem(Item* item, int x, int y, const char* name, bool isKey) {
    item->x = x;
    item->y = y;
    item->active = true;
    item->isKey = isKey;
    strcpy(item->name, name);
}
