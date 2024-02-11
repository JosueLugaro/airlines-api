# airlines-api

Welcome to the airlines-api, a REST api built in C++. I started building this to practice C++
and introduce myself to the C++ ecosystem. The airlines-api utilizes [libhttpserver](https://github.com/etr/libhttpserver)
to facilitate the request-response cycle and [libpqxx](https://github.com/jtv/libpqxx) to interface
with the PostgreSQL database which stores the air travel related data.

## Dependencies:

- [libhttpserver](https://github.com/etr/libhttpserver)
- [libmicrohttp](https://www.gnu.org/software/libmicrohttpd/) (libhttpserver is built on top of libmicrohttp)
- [libpqxx](https://github.com/jtv/libpqxx)
- [libpq](https://www.postgresql.org/docs/current/libpq.html) (libpqxx dependency)

## Endpoints (WIP)

- `/hello` Test endpoint
