# original class

## dict.hpp
文字列キーのmapラッパー  
push_backメンバ関数を持ち  
格納順で値を保持する  
atで呼び出せる  
findはない（かわりにboolを返すexist関数がある）  

## coord.hpp
座標系のクラス

## file.hpp
fileをSTLコンテナのように扱うfstreamラッパー  
コンストラクタ（文字列、demilita）でファイルを開く  
参照外しで文字列になるfile_iteratorを持つ  

## tags.hpp
constexpr定文字列をいくつか  

## regex.hpp
boost::xpressiveの名前が長いのでラップした  
regex_interatorをSTLコンテナのように扱うregex_range  
regex_token_iteratorを以下略  

## mixin/
CRTPで継承して使用する  
自分しか得をしない作りこみパーサ  