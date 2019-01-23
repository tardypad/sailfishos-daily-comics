function(page) {
    var regex1 = /<img[^>]*src="([^"]*english[^"]*)"/;
    var match1 = regex1.exec(page);

    if (match1 !== null) {
        return match1[1];
    }

    var regex2 = /<img[^>]*src="([^"]*[eE][nN][\.-][^"]*)"/;
    var match2 = regex2.exec(page);
    return match2[1];
}
