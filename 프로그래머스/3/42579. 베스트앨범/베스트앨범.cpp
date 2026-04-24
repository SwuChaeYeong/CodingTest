#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> genreTotal;
    unordered_map<string, vector<pair<int, int>>> genreSongs;
    
    for (int i = 0; i < genres.size(); i++)
    {
        genreTotal[genres[i]] += plays[i];
        genreSongs[genres[i]].push_back({plays[i], i});
    }
    
    // 정렬
    vector<pair<string, int>> sortedGenres(genreTotal.begin(), genreTotal.end());
    sort(sortedGenres.begin(), sortedGenres.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    
    // 장르별 노래 선택
    for (auto &g : sortedGenres) {
        auto &songs = genreSongs[g.first];
        
        sort(songs.begin(), songs.end(), [](auto &a, auto &b) {
            if (a.first == b.first)
                return a.second < b.second; // 인덱스 작은 거 먼저
            return a.first > b.first;     // 재생수 큰 거 먼저
        });
        
        // 최대 2개 선택
        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }
    
    return answer;
}