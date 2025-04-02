+----------------+      +----------------+      +------------------+
|     Start      |----->|  Check login   |----->|    Decision      |
| statisticsMenu |      |    status      |      |    branch        |
+----------------+      +----------------+      +--------+---------+
                                                         |
         +-------------------------------------------------+-------------+
         |                                                               |
         v                                                               v
+----------------+                                              +------------------+
| Not logged in  |                                              |    Logged in     |
| Show error     |                                              |    Check book    |
| & return       |                                              |    availability  |
+----------------+                                              +--------+---------+
                                                                         |
                                          +--------------------------+---+----------------+
                                          |                          |                    |
                                          v                          v                    |
                                +-----------------+       +-------------------+           |
                                |  Library empty  |       |   Books exist     |           |
                                |  Show message   |       |   Display menu:   |           |
                                |  & return       |       |   1. By Category  |           |
                                +-----------------+       |   2. By Year      |           |
                                                          |   3. Most Popular |           |
                                                          |   4. Most Available|          |
                                                          |   5. Most Expensive|          |
                                                          |   6. Overall Stats |          |
                                                          |   0. Back         |           |
                                                          +---------+---------+           |
                                                                    |                     |
                                                                    v                     |
                                                          +-------------------+           |
                                                          |  Get user choice  |           |
                                                          +--------+----------+           |
                                                                   |                      |
              +-------------+-------------+-------------+----------+----------+-----------+----------+
              |             |             |             |          |          |                      |
              v             v             v             v          v          v                      v
      +-------------+ +------------+ +------------+ +------------+ +------------+ +-------------+ +------------+
      |  Option 0   | | Option 1   | | Option 2   | | Option 3   | | Option 4   | | Option 5    | | Option 6   |
      |  Return to  | | Books by   | | Books by   | | Most       | | Most       | | Most        | | Overall    |
      |  main menu  | | Category   | | Year       | | Popular    | | Available  | | Expensive   | | Statistics |
      +-------------+ +------+-----+ +------+-----+ +------+-----+ +------+-----+ +------+------+ +------+-----+
                             |             |             |             |             |              |
                             v             v             v             v             v              v
                     +-------------+  +------------+ +------------+ +------------+ +------------+ +------------+
                     | 1. Count    |  | 1. Count   | | 1. Copy    | | 1. Copy    | | 1. Copy    | | 1. Calculate|
                     | by category |  | by year    | | library    | | library    | | library    | | totals:    |
                     +------+------+  +------+-----+ | array      | | array      | | array      | | books,     |
                            |                |       +------+-----+ +------+-----+ +------+-----+ | quantities,|
                            v                v              v             v             v         | borrowed,   |
                     +-------------+  +------------+  +------------+ +------------+ +------------+ | value      |
                     | 2. Find     |  | 2. Sort    |  | 2. Sort by | | 2. Sort by | | 2. Sort by | +------+-----+
                     | unique      |  | years      |  | borrowed   | | available  | | price      |        |
                     | categories  |  | chronolog. |  | (desc)     | | (desc)     | | (desc)     |        v
                     +------+------+  +------+-----+  +------+-----+ +------+-----+ +------+-----+ +------------+
                            |                |               |             |             |         | 2. Display  |
                            v                v               v             v             v         | overall     |
                     +-------------+  +------------+  +------------+ +------------+ +------------+ | metrics     |
                     | 3. Find max |  | 3. Find max|  | 3. Display | | 3. Calc.   | | 3. Display | +------+-----+
                     | count for   |  | count for  |  | top 5 books| | available  | | top 5 books|        |
                     | scaling     |  | scaling    |  | (or fewer) | | quantities | | (or fewer) |        v
                     +------+------+  +------+-----+  +------------+ +------+-----+ +------------+ +------------+
                            |                |                           |                         | 3. Display  |
                            v                v                           v                         | bar charts  |
                     +-------------+  +------------+              +------------+                   | for inventory|
                     | 4. Display  |  | 4. Display |              | 4. Display |                   | status      |
                     | bar chart   |  | bar chart  |              | top 5 books|                   +------------+
                     | for each    |  | for each   |              | (or fewer) |
                     | category    |  | year       |              +------+-----+
                     +------+------+  +------+-----+                     |
                            |                |                           |
                            +----------------+---------------------------+----------------+
                                                                                         |
                                                                                         v
                                                                               +-------------------+
                                                                               | Add delay         |
                                                                               | (MEDIUM_DELAY)    |
                                                                               +--------+----------+
                                                                                        |
                                                                                        v
                                                                               +-------------------+
                                                                               | Continue with     |
                                                                               | menu loop         |
                                                                               +-------------------+