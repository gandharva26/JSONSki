#include "../src/RecordLoader.h"
#include "../src/JSONSki.h"

int main() {
    char* file_path = "../dataset/twitter_sample_large_record.json";
    cout<<"start loading the single large record from "<<file_path<<endl;
    Record* rec = RecordLoader::loadSingleRecord(file_path);
    if (rec == NULL) {
        cout<<"record loading fails."<<endl;
        return -1;
    }
    cout<<"finish loading the single large record"<<endl;

    string query = "$[*].entities.urls[*].url";
    cout<<"\nstart executing query "<<query<<endl;
    string output = JSONSki::runQuery(rec, query);
    cout<<"finish query execution"<<endl;
    cout<<"matches are: "<<output<<endl;
    return 0;
}