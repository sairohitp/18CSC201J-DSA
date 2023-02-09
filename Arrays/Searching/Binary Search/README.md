## Binary Search

### Pseudocode

```
low = 0
high = array.length
mid = low + high / 2

Compare key with mid

if key == mid
    return mid i.e found
elseif key < mid
    high = mid - 1
elseof key > mid
    low = mid + 1
else
    not found
```

Repeat until array gets exhausted.