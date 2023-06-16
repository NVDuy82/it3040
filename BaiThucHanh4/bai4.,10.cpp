// Nguyen Van Duy - 20215334
/*
Bài 4.10. Xây dựng một máy tìm kiếm (search engine) đơn giản.
Cho  N  văn bản và  Q  truy vấn.
Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất.

Sử dụng phương pháp tính điểm TF-IDF
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Document {
private:
    vector<string> t;
    map<string, int> f;
    map<string, double> tf;
public:
    Document() = default;

    explicit Document(const vector<string> &t) : t(t) {}

    virtual ~Document() {
        std::destroy(t.begin(), t.end());
    }

    [[nodiscard]] int size() const { return t.size(); }

    [[nodiscard]] const string &operator[](int i) const { return t[i]; }

    friend ostream &operator<<(ostream &os, const Document &d) {
        for (int i = 0; i < d.size(); ++i) {
            os << d[i] << endl;
        }
        return os;
    }

    friend bool operator==(const Document &d1, const Document &d2) {
        return d1.t == d2.t;
    }

    friend bool operator!=(const Document &d1, const Document &d2) {
        return !(d1 == d2);
    }

    friend bool operator<(const Document &d1, const Document &d2) {
        return d1.t < d2.t;
    }

    friend bool operator>(const Document &d1, const Document &d2) {
        return d1.t > d2.t;
    }

    friend bool operator<=(const Document &d1, const Document &d2) {
        return d1.t <= d2.t;
    }

    friend bool operator>=(const Document &d1, const Document &d2) {
        return d1.t >= d2.t;
    }

    friend Document operator+(const Document &d1, const Document &d2) {
        Document d(d1.t);
        d.t.insert(d.t.end(), d2.t.begin(), d2.t.end());
        return d;
    }

    int f_td(string _t, bool recalc = false) {
        if (f.find(_t) != f.end() && !recalc) {
            return f[_t];
        } else {
            int count = 0;
            for (const auto & i : t) {
                if (i == _t) {
                    count++;
                }
            }
            f[_t] = count;
            return count;
        }
    }

    double tf_td(string _t, bool recalc = false) {
        if (tf.find(_t) != tf.end() && !recalc) {
            return tf[_t];
        } else {
            double res; // result
            int max_f = INT_MIN;
            for (const auto & i : f) {
                if (i.second > max_f) {
                    max_f = i.second;
                }
            }
            res = 0.5 + 0.5 * f_td(_t) / max_f;
            tf[_t] = res;
            return res;
        }
    }

    bool contains(string _t) {
        return f_td(_t, true) != 0;
    }
};

class Documents {
private:
    vector<Document> d;
public:
    Documents() = default;

    explicit Documents(const vector<Document> &d) {
        this->d = d;
    }

    explicit Documents(int n) {
        for (int i = 0; i < n; ++i) {
            d.emplace_back();
        }
    }

    virtual ~Documents() {
        std::destroy(d.begin(), d.end());
    }

    void add(const Document& doc) {
        this->d.push_back(doc);
    }

    void remove(const int index) {
        d.erase(d.begin() + index);
    }

    void remove(const Document& doc) {
        for (int i = 0; i < d.size(); ++i) {
            if (d[i] == doc) {
                d.erase(d.begin() + i);
                return;
            }
        }
    }

    Documents &operator=(const Documents &d) = default;

    [[nodiscard]] int size() const { return d.size(); }

    [[nodiscard]] const Document &operator[](int i) const { return d[i]; }

    friend ostream & operator<<(ostream & os, Document &documents) {
        for (int i = 0; i < documents.size(); ++i) {
            os << documents[i] << endl;
        }
        return os;
    }

    int df(string t) {
        int count = 0;
        for (auto & i : d) {
            if (i.contains(t)) {
                count++;
            }
        }
        return count;
    }

    double idf(string t) {
        int n = d.size();
        return log2(n / df(t));
    }

    double score(string t, int index_doc) {
        return d[index_doc].tf_td(t) * idf(t);
    }
};

class Query {
private:
    vector<string> t;
    vector<double> score;
public:
    Query() = default;

    explicit Query(const vector<string> &t) : t(t) {}

    void calc(Documents documents) {
        for (int i = 0; i < documents.size(); ++i) {
            score.push_back(0.0);
            for (int j = 0; j < t.size(); ++j) {
                score[i] += documents.score(t[j], i);
            }
        }
    }

    double get_score(int index_doc) {
        return score[index_doc];
    }

    friend ostream & operator<<(ostream & os, Query query) {
        for (const auto & i : query.score) {
            os << i << " ";
        }
        return os;
    }
};

class Queries {
private:
    vector<Query> queries;
public:
    Queries() = default;

    explicit Queries(const vector<Query> &queries) {
        this->queries = queries;
    }

    void add(const Query & q) {
        this->queries.push_back(q);
    }

    void calc(Documents documents) {
        for (int i = 0; i < queries.size(); ++i) {
            queries[i].calc(documents);
        }
    }

    double score(int index_query, int index_doc) {
        return this->queries[index_query].get_score(index_doc);
    }

    friend ostream & operator<<(ostream & os, Queries q) {
        for (const auto & i : q.queries) {
            os << i << endl;
        }
        return os;
    }
};

int main() {
    Documents docs;
    docs.add(Document({"k", "k", "ow"}));
    docs.add(Document({"bb", "ar", "h"}));
    docs.add(Document({"qs", "qs", "qs"}));
    docs.add(Document({"qs", "qs", "qs"}));
    docs.add(Document({"d", "bb", "q", "d", "rj"}));
    docs.add(Document({"ow"}));

    Queries queries;
    queries.add(Query({"h", "d", "d", "qs", "q", "q", "ar"}));
    queries.add(Query({"qs", "qs"}));
    queries.add(Query({"hc", "d", "ow", "d", "qs"}));
    queries.add(Query({"ow", "wl", "hc", "k"}));
    queries.add(Query({"q", "hc", "q", "d", "hc", "q"}));

    queries.calc(docs);
    cout << queries << endl;

    return 0;
}

// Nguyen Van Duy - 20215334
