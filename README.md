# Data-structures
Education project by Cybersecurity student to understand data structures and train C/C++

# Design philosophy
All modules in this repository are designed using these principles:
- Error handling: Functions that modify data structures return bool type. They return ```true``` when operation was a success or ```false``` when operation failed
- Memory management: All data structures are created using ```_create``` functions and they manage their own memory. User is responsible for calling ```_free``` functions to free memory used by structures
- Genericity: All data structures are implemented in a generic way. C modules are implemented by using ```void*``` and ```memcpy``` which puts responsibility for type casting and providing correct data sizes on user

# Modules
As for now, repository containes these modules:
- C Stack

# C Stack
Secure, generic stack implementation in C programing language. 

| Function | Description|
|---|---|
