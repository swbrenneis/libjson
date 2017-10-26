#include <seComm/json/Document.h>
#include <seComm/json/Object.h>
#include <seComm/json/Variant.h>
#include <seComm/json/Exception.h>
#include <sstream>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {

    if (argc == 2) {
        std::string filename(argv[1]);
        std::ifstream file(filename);
        try {
            std::cout << "Parsing " << filename << std::endl;
            sejson::Document *doc = sejson::Document::fromStream(file);
            file.close();
            sejson::Variant var = doc->getVariant();
            std::ostringstream ijstr;
            var.toJson(ijstr);
            std::cout << "JSON out = " << ijstr.str() << std::endl;
            delete doc;
        }
        catch (sejson::Exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    else { 
        sejson::Object test1;
        test1["var1"] = 10;
        std::ostringstream d1str;
        test1.toJson(d1str);
        std::cout << "test1 JSON out = " << d1str.str() << std::endl;

        sejson::Object test2;
        test2["test2"] = test1;
        std::ostringstream d2str;
        test2.toJson(d2str);
        std::cout << "test2 JSON out = " << d2str.str() << std::endl;

        test1["var1"] = 11;
        std::ostringstream d3str;
        test2.toJson(d3str);
        std::cout << "test3 JSON out = " << d3str.str() << std::endl;
    }

}

