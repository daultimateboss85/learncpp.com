int v1{ 45 };
int* ptr{ &v1 }; // initialize ptr with address of v1

int v2 { 78 };
*ptr = &v2;     // assign ptr to address of v2

/* we are actually trying to assign what is at the address held in ptr to the address of v2
essentialy should just be ptr = &v2*/