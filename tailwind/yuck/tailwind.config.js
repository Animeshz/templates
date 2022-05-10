module.exports = {
  content: {
    files: ['*.yuck'],
    extract: {
      yuck: (content) => {
        let v = [...content.matchAll(/:class "((\${.*?}|[^"])*)/g)]
        v = v.map(a => a[1])
        v = v.map(e => e.replace(/\${.*?\?([^}]+)}/g, (s,g1) => g1))
        v = v.map(e => e.replace(/['"\\]/g, ""))
        v = v.flatMap(e => e.split(/\s+/))
        return v
      }
    }
  },
  theme: {
    extend: {},
  },
  plugins: [],
}
