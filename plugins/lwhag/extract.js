function(page) {
    var regex1 = /<img[^>]*src="([^"]*en-[^"]*x[^"]*\.[^"]*)"/;
    var match1 = regex1.exec(page);

    if (match1 !== null) {
        return match1[1];
    }

    var regex2 = /<a\shref="([^"]*en\.[^"]*)"/;
    var match2 = regex2.exec(page);
    return match2[1];
}
