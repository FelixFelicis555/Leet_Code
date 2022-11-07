class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_log=[]
        digit_log=[]
        output=[]
        for l in logs:
            if l.split()[1].isdigit():
                digit_log.append(l)
            else:
                letter_log.append(l)
        letter_log = sorted(letter_log, key = lambda x: (x.split(' ',1)[1], x.split(' ',1)[0]))
        output+=letter_log + digit_log
        return output
        