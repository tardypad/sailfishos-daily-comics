function(page) {
    //var regex = /<div id="comicpanel".*?<p>.*?<img.+?src="([^"]*)"/
    var regex = /<div id="comicpanel"[^]*?<p>[^]*?<img.+?src="([^"]*)"/
    var match = regex.exec(page);
    return match[1]
}
