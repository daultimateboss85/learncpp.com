int main()
{
    int a { 5 }; // 1a no conversion
    int b { 'a' }; // 1b numeric promotion
    int c { 5.4 }; // 1c narrowing conversion
    int d { true }; // 1d numeric promotion
    int e { static_cast<int>(5.4) }; // 1e narrowing conversion

    double f { 5.0f }; // 1f numeric promotion
    double g { 5 }; // 1g depends 

    // Extra credit section
    long h { 5 }; // 1h conversion

    float i { f }; // 1i (uses previously defined variable f) conversion
    float j { 5.0 }; // 1j conversion

}