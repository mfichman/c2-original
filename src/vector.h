/*
 * Copyright (c) 2014 Matt Fichman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, APEXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */


#define vector_define(N,T) \
typedef struct N { \
    T * element;\
    uint32_t count;\
    uint32_t capacity;\
} N;\
static inline N* N##_new() {\
    N* self = malloc(sizeof(N));\
    self->capacity = 32;\
    self->count = 0;\
    self->element = malloc(sizeof(T)*self->capacity);\
    return self;\
}\
static inline void N##_push(N* self, T element) {\
    if((self->count+1)>self->capacity) {\
        self->capacity *= 2;\
        self->element = realloc(self->element,sizeof(T)*self->capacity);\
    }\
    self->element[self->count++] = element;\
}

