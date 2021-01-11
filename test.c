

void insert(node* entry){
    double priority = entry->endTime;

    // i la vi tri bucket ma entry chen vao
    int i;
    i = priority / width;
    i = i % nbuckets;

    /*Chèn entry vào vị trí thích hợp trong bucket thứ i*/

    // Cập nhất qsize 
    qsize++;

    return;
}


