function(page) {
    var regex = /<div class="daily-strip-wrapper">[^]*?<img.*? src="([^"]*)"/;
    var match = regex.exec(text);
    return match[1];
}
