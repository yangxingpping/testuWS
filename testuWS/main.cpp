

#include "uWS/uWS.h"

#include <string>
#include <string_view>
#include <iostream>

int main()
{
	using namespace uWS;
	using namespace std;
	uWS::Hub h;

	h.onHttpRequest([](HttpResponse* resp, HttpRequest req, char* data, size_t len, size_t remain) {
		string str{ "hello.world" };
		resp->end(str.c_str(), str.length());
		});
	
	h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
		ws->send(message, length, opCode);
		});
	uS::Async _async(h.getLoop());
	_async.start([](uS::Async* handle) {
		cout << "hello.world" << endl;
		});
	if (h.listen("127.0.0.1",3000)) {
		
		h.run();
	}
}