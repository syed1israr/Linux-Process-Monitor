linux-process-monitor/
│
├── src/                        # All source code
│   ├── cli/                   # ncurses-based UI (your module)
│   │   └── cli.cpp
│   ├── core/                  # Business logic
│   │   ├── scheduler.cpp      # Scheduling logic
│   │   ├── parser.cpp         # /proc data parser
│   │   └── monitor.cpp        # CPU/memory monitor
│   ├── threads/               # Multithreading logic
│   │   └── thread_pool.cpp
│   ├── ipc/                   # Sockets and IPC
│   │   ├── socket_server.cpp
│   │   └── ipc_handler.cpp
│   └── main.cpp               # Entry point
│
├── include/                   # Header files
│   ├── cli.hpp
│   ├── scheduler.hpp
│   ├── parser.hpp
│   ├── monitor.hpp
│   ├── thread_pool.hpp
│   ├── socket_server.hpp
│   └── ipc_handler.hpp
│
├── tests/                     # Unit tests
│   ├── test_parser.cpp
│   └── test_scheduler.cpp
│
├── scripts/                   # Optional helper scripts
│   ├── install_deps.sh
│   └── run_monitor.sh
│
├── Makefile                   # Build file
├── README.md                  # Project overview
└── .gitignore                 # Git ignored files
