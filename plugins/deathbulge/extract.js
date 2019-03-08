function(page) {
    var regex = /<div id="comic">[^]*?<img id="comic-image"[^>]*? src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
