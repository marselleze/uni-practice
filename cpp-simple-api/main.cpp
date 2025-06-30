#include <cstdlib>
#include <drogon/HttpAppFramework.h>
#include <drogon/drogon.h>

using namespace drogon;

typedef std::function<void(const HttpResponsePtr &)> Callback;

void nameHandler(const HttpRequestPtr &request, Callback &&callback) {
    Json::Value jsonBody;
    auto requestBody = request->getJsonObject();

    if (requestBody == nullptr) {
        jsonBody["status"] = "error";
        jsonBody["message"] = "body is required";

        auto response = HttpResponse::newHttpJsonResponse(jsonBody);
        response->setStatusCode(HttpStatusCode::k400BadRequest);

        callback(response);
        return;
    }

    if (!requestBody->isMember("name")) {
        jsonBody["status"] = "error";
        jsonBody["message"] = "field `name` is required";

        auto response = HttpResponse::newHttpJsonResponse(jsonBody);
        response->setStatusCode(HttpStatusCode::k400BadRequest);

        callback(response);
        return;
    }

    auto name = requestBody->get("name", "guest").asString();

    jsonBody["message"] = "Hello, " + name + "!";

    auto response = HttpResponse::newHttpJsonResponse(jsonBody);
    callback(response);
}

int main() {
    app()
    // Слушаем алрес 0.0.0.0 с портом 3000
    .addListener("0.0.0.0", 3000)
    .setThreadNum(8)
    .enableServerHeader(false)
    .registerHandler("/name", &nameHandler, {Post})
    .run();

    return EXIT_SUCCESS;
}