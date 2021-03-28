#include <cstddef>
#include <cstdio>
#include <new>

constexpr size_t kilobytes(size_t n) {
  return n * 1024;
}

struct Bucket {
  const static size_t data_size{kilobytes(4)};
  std::byte data[data_size];
};
struct LargeBucket {
  const static size_t data_size{kilobytes(1024)};
  std::byte data[data_size];
};

struct Heap {
  void* allocate(size_t bytes) {
    if (bytes > LargeBucket::data_size) throw std::bad_alloc{};
    if (bytes > Bucket::data_size) {
      for (size_t i{}; i<n_heap_buckets; i++) {
        if (!large_bucket_used[i]) {
          printf("allocating large bucket...");
          large_bucket_used[i] = true;
          return large_buckets[i].data;
        }
      }
    }
    for(size_t i{}; i<n_heap_buckets; i++) {
      if (!bucket_used[i]) {
        printf("allocating bucket...");
        bucket_used[i] = true;
        return buckets[i].data;
      }
    }
    throw std::bad_alloc{};
  }

  void free(void* p) {
    for (size_t i{}; i < n_heap_buckets; i++) {
      if(buckets[i].data == p) {
        bucket_used[i] = false;
        return;
      }
      if(large_buckets[i].data == p) {
        large_bucket_used[i] = false;
        return;
      }
    }
  }

  static const size_t n_heap_buckets{10};
  Bucket buckets[n_heap_buckets]{};
  LargeBucket large_buckets[n_heap_buckets]{};
  bool bucket_used[n_heap_buckets]{};
  bool large_bucket_used[n_heap_buckets]{};
};

Heap heap;
void* operator new(size_t n_bytes) { return heap.allocate(n_bytes); }
void operator delete(void* p) { return heap.free(p); }

int main() {
  auto breakfast = new unsigned int[1024*256];
  breakfast[1024*256] = 3;
  printf("%d\n", breakfast[1024*256-1]);
}