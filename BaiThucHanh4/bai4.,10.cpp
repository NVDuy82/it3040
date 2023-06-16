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

    ~Document() {
        t.clear();
        t.shrink_to_fit();
        f.clear();
        tf.clear();
    }

    [[nodiscard]] int size() const { return t.size(); }

    [[nodiscard]] const string &operator[](int i) const { return t[i]; }

    Document & operator=(const Document & d) = default;

    friend ostream &operator<<(ostream &os, const Document d) {
        int i;
        for (i = 0; i < d.size() - 1; ++i) {
            os << d[i] << ", ";
        }
        os << d[i];
        return os;
    }

    friend istream &operator>>(istream &is, Document &d) {
        string s;
        is >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ',') {
                d.t.push_back(s.substr(0, i));
                s = s.substr(i + 1);
                i = -1;
            }
        }
        d.t.push_back(s);
        return is;
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
            int max_f = 0;
            for (const auto & i : f) {
                if (i.second > max_f) {
                    max_f = i.second;
                }
            }
            res = max_f ? (0.5 + 0.5 * f_td(_t) / max_f) : 0;
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
    
    ~Documents() {
        d.clear();
        d.shrink_to_fit();
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

    [[nodiscard]] const Document &operator[](int i) const { return d[i]; }

    Documents &operator=(const Documents& docs) {
        this->d.clear();
        for (int i = 0; i < docs.size(); i++) {
            this->d.push_back(docs[i]);
        }
        return *this;
    }

    [[nodiscard]] int size() const { return d.size(); }

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
        return df(t) ? log2(n / df(t)) : 0;
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
    
    ~Query() {
        t.clear();
        t.shrink_to_fit();
        score.clear();
        score.shrink_to_fit();
    }

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

    int search_index() {
        int res = 0;
        for (int i = 0; i < score.size(); ++i) {
            if (score[i] > score[res]) {
                res = i;
            }
        }
        return ++res;
    }

    [[nodiscard]] int size() { return t.size(); }

    [[nodiscard]] const string &operator[](int i) const { return t[i]; }

    friend ostream & operator<<(ostream & os, Query query) {
        int i;
        for (i = 0; i < query.size() - 1; i++) {
            os << query[i] << ", ";
        }
        os << query[i];
        return os;
    }

    friend istream & operator>>(istream & is, Query &query) {
        string s;
        is >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ',') {
                query.t.push_back(s.substr(0, i));
                s = s.substr(i + 1);
                i = -1;
            }
        }
        query.t.push_back(s);
        return is;
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
    
    ~Queries() {
        queries.clear();
        queries.shrink_to_fit();
    }

    [[nodiscard]] int size() { return queries.size(); }

    [[nodiscard]] const Query &operator[](int i) const { return queries[i]; }

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
        int i;
        for (i = 0; i < q.size() - 1; i++) {
            os << q[i] << endl;
        }
        os << q[i];
        return os;
    }
};

int main() {
    int n, q;
    Documents docs;
    Queries queries;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        Document document;
        cin >> document;
        docs.add(document);
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        Query query;
        cin >> query;
        queries.add(query);
    }

    queries.calc(docs);

    for (int i = 0; i < queries.size(); ++i) {
        Query q = queries[i];
        cout << q.search_index() << endl;
    }

    return 0;
}

// Nguyen Van Duy - 20215334
