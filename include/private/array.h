#ifndef REFLECS_ARRAY_H
#define REFLECS_ARRAY_H

#include <reflecs/reflecs.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsArray EcsArray;

typedef int (*EcsComparator)(
    const void* p1,
    const void *p2);

typedef struct EcsArrayParams {
    uint32_t element_size; /* Size of an element */
    EcsComparator compare_action; /* Comparator function */
} EcsArrayParams;

typedef struct EcsArrayIter {
    EcsArrayParams *params;
    uint32_t index;
} EcsArrayIter;

REFLECS_EXPORT
EcsArray* ecs_array_new(
    uint32_t size,
    const EcsArrayParams *params);

REFLECS_EXPORT
EcsArray* ecs_array_new_from_buffer(
    uint32_t size,
    const EcsArrayParams *params,
    void *buffer);

REFLECS_EXPORT
void ecs_array_free(
    EcsArray *array);

REFLECS_EXPORT
EcsArray* ecs_array_add(
    EcsArray *array,
    const EcsArrayParams *params,
    void *elem_out);

REFLECS_EXPORT
void* ecs_array_get(
    EcsArray *array,
    const EcsArrayParams *params,
    uint32_t index);

REFLECS_EXPORT
EcsArray* ecs_array_remove(
    EcsArray *array,
    const EcsArrayParams *params,
    uint32_t index);

REFLECS_EXPORT
uint32_t ecs_array_count(
    EcsArray *array);

REFLECS_EXPORT
uint32_t ecs_array_size(
    EcsArray *array);

REFLECS_EXPORT
void* ecs_array_buffer(
    EcsArray *array);

REFLECS_EXPORT
EcsIter _ecs_array_iter(
    EcsArray *array,
    const EcsArrayParams *params,
    EcsArrayIter *iter_data);

#define ecs_array_iter(me, params)\
    _ecs_array_iter(me, params, alloca(sizeof(EcsArrayIter)))

REFLECS_EXPORT
void ecs_array_sort(
    EcsArray *array,
    const EcsArrayParams *params);

#ifdef __cplusplus
}
#endif

#endif