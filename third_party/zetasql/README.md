This is a partial copy of https://github.com/google/zetasql.

We want to use libraries in [zetasql/base](https://github.com/google/zetasql/tree/7d983d3632702f200c8340933160c02f1d94e5a7/zetasql/base). However, these libraries are [marked](https://github.com/google/zetasql/blob/7d983d3632702f200c8340933160c02f1d94e5a7/zetasql/base/BUILD#L19) only visible to other zetasql packages. Therefore, we make a copy of the C++ code here, and supply our own BUILD file.
