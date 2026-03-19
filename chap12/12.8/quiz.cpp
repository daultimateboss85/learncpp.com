/*
1a if pointer{} as pointers implicitly convert to bool with null pointers
being false

1b no easy way to determine

2a predictable

2b predictable

2c predictable

2d undefined

2e undefined

2f if dangling you are cooked

3 so we can then check and know not to use them otherwise it is not easy 
to determine if a pointer is dangling or not
*/