import nltk


class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        # TODO
        self.positives = set()
        self.negatives = set()

        file = open(positives, "r")
        for word in file:
            if word.startswith(";"):
                continue
            else:
                self.positives.add(word.strip())

        file = open(negatives, "r")
        for word in file:
            if word.startswith(";"):
                continue
            else:
                self.negatives.add(word.strip())

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        # TODO
        score = 0
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)

        for word in tokens:
            if word.lower() in self.positives:
                score += 1
            elif word.lower() in self.negatives:
                score -= 1

        return score


