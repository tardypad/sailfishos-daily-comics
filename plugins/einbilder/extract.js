function(page) {
    var regex = /<meta\sproperty="og:image"\scontent="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
