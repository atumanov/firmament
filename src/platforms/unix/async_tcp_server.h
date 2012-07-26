// The Firmament project
// Copyright (c) 2011-2012 Malte Schwarzkopf <malte.schwarzkopf@cl.cam.ac.uk>
//
// Asynchronous TCP server class.

#ifndef FIRMAMENT_PLATFORMS_UNIX_ASYNC_TCP_SERVER_H
#define FIRMAMENT_PLATFORMS_UNIX_ASYNC_TCP_SERVER_H

#include <boost/asio.hpp>

#include <string>
#include <vector>

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include "base/common.h"
#include "misc/messaging_interface.h"
#include "misc/uri_tools.h"
#include "platforms/common.h"
#include "platforms/unix/tcp_connection.h"

namespace firmament {
namespace platform_unix {
namespace streamsockets {

// Asynchronous, multi-threaded TCP server.
// Design inspired by
// http://www.boost.org/doc/html/boost_asio/example/http/server3/server.hpp.
class AsyncTCPServer : private boost::noncopyable {
 public:
  explicit AsyncTCPServer(const string& endpoint_addr, const string& port);
  void Run();
  void Stop();
  TCPConnection::connection_ptr connection(uint64_t connection_id) {
    CHECK_LT(connection_id, active_connections_.size());
    return active_connections_[connection_id];
  }
  inline bool listening() { return listening_; }
 private:
  bool listening_;
  void StartAccept();
  void HandleAccept(TCPConnection::connection_ptr connection,
                    const boost::system::error_code& error);
  boost::asio::io_service io_service_;
  tcp::acceptor acceptor_;
  vector<TCPConnection::connection_ptr> active_connections_;
};

}  // namespace streamsockets
}  // namespace platform_unix
}  // namespace firmament

#endif  // FIRMAMENT_PLATFORMS_UNIX_ASYNC_TCP_SERVER_H